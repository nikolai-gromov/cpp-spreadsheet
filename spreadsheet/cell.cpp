#include "cell.h"

#include <cassert>
#include <iostream>
#include <string>
#include <optional>

class Cell::Impl {
public:
    Impl(SheetInterface& sheet, std::string text)
        : sheet_(sheet)
        , text_(text) {
    }

    Impl(SheetInterface& sheet)
        : sheet_(sheet) {
    }

    virtual ~Impl() = default;

    virtual Value GetValue() const = 0;

    virtual std::string GetText() const = 0;

    virtual std::vector<Position> GetReferencedCells() const = 0;

protected:
    SheetInterface& sheet_;
    std::string text_;
};

class Cell::EmptyImpl : public Impl {
public:
    EmptyImpl(SheetInterface& sheet)
        : Impl(sheet) {
    }

    Value GetValue() const override  {
        return text_;
    }

    std::string GetText() const override {
        return text_;
    }

    std::vector<Position> GetReferencedCells() const override {
        return {};
    }
};

class Cell::TextImpl : public Impl {
public:
    TextImpl(SheetInterface& sheet, std::string text)
        : Impl(sheet, text) {
    }

    Value GetValue() const override  {
        if (!text_.empty() && text_.front() == '\'') {
            return text_.substr(1);
        }
        return text_;
    }

    std::string GetText() const override {
        return text_;
    }

    std::vector<Position> GetReferencedCells() const override {
        return {};
    }
};

class Cell::FormulaImpl : public Impl {
public:
    FormulaImpl(SheetInterface& sheet, std::string text)
        : Impl(sheet, text) {
        try {
            formula_ = ParseFormula(text);
        } catch (const std::exception& exc) {
            std::throw_with_nested(FormulaException(exc.what()));
        }
    }

    Value GetValue() const override {
        FormulaInterface::Value val = formula_.get()->Evaluate(sheet_);
        if (std::holds_alternative<FormulaError>(val)) {
            return std::get<FormulaError>(val);
        }
        return std::get<double>(val);
    }

    std::string GetText() const override {
        return "=" + formula_.get()->GetExpression();
    }

    std::vector<Position> GetReferencedCells() const override {
        std::vector<Position> list_cells = formula_->GetReferencedCells();
        for (auto it = list_cells.begin(); it != list_cells.end(); ++it) {
            if (!(sheet_.GetCell(*it))) {
                sheet_.SetCell(*it, "");
            }
        }
        return list_cells;
    }

private:
    std::unique_ptr<FormulaInterface> formula_;
};

void Cell::CheckCellForCyclicDependencies(const CellInterface* cell) const {
    if (this == cell) {
        throw CircularDependencyException("Cyclic dependency");
    }
    for (Position pos : cell->GetReferencedCells()) {
        CheckCellForCyclicDependencies(sheet_.GetCell(pos));
    }
}

void Cell::SearchForCyclicDependencies(const std::unique_ptr<FormulaImpl>& impl) const {
    for (Position pos : impl->GetReferencedCells()) {
        CheckCellForCyclicDependencies(sheet_.GetCell(pos));
    }
}

void Cell::CacheReset() {
    value_cache_.reset();
    for (Cell* cell_ptr : dependent_cells_) {
        cell_ptr->CacheReset();
    }
}

void Cell::UpdateDependecies(Update upd) {
    for (Position pos : GetReferencedCells()) {
        CellInterface* cell_ptr = sheet_.GetCell(pos);
        if (cell_ptr) {
            if (Update::REMOVE == upd) {
                static_cast<Cell*>(cell_ptr)->dependent_cells_.erase(this);
            } else {
                static_cast<Cell*>(cell_ptr)->dependent_cells_.insert(this);
            }
        }
    }
}

Cell::Cell(SheetInterface& sheet)
    : sheet_(sheet) {
    impl_ = std::make_unique<EmptyImpl>(sheet_);
}

Cell::~Cell() {}

void Cell::Set(std::string text) {
    CacheReset();
    UpdateDependecies(Update::REMOVE);
    if (!text.empty()) {
        if (text.size() > 1 && text.front() == '=') {
            std::unique_ptr<FormulaImpl> impl_tmp = std::make_unique<FormulaImpl>(sheet_, text.substr(1));
            SearchForCyclicDependencies(impl_tmp);
            impl_ = std::move(impl_tmp);
            UpdateDependecies(Update::ADD);
        } else {
            impl_ = std::make_unique<TextImpl>(sheet_, text);
        }
    } else {
        impl_ = std::make_unique<EmptyImpl>(sheet_);
    }
}

void Cell::Clear() {
    Set("");
}

Cell::Value Cell::GetValue() const {
    if (value_cache_ == std::nullopt) {
        value_cache_ = impl_->GetValue();
    }
    return value_cache_.value();
}

std::string Cell::GetText() const {
    return impl_.get()->GetText();
}

std::vector<Position> Cell::GetReferencedCells() const {
    return impl_->GetReferencedCells();
}