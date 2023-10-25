#include "cell.h"

#include <cassert>
#include <iostream>
#include <string>
#include <optional>
#include <functional>

class Cell::Impl {
public:
    virtual ~Impl() = default;

    virtual Value GetValue(const Sheet& sheet) const = 0;
    virtual std::string GetText() const = 0;

    virtual std::vector<Position> GetReferencedCells() const = 0;
};

class Cell::EmptyImpl : public Cell::Impl {
public:
    Value GetValue(const Sheet& sheet) const override  {
        return {};
    }

    std::string GetText() const override {
        return "";
    }

    std::vector<Position> GetReferencedCells() const override {
        return {};
    }
};

class Cell::TextImpl : public Cell::Impl {
public:
    TextImpl(std::string text)
        : text_(std::move(text)) {
    }

    Value GetValue(const Sheet& sheet) const override  {
        if (!text_.empty() && text_.front() == ESCAPE_SIGN) {
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

private:
    std::string text_;
};

class Cell::FormulaImpl : public Impl {
public:
    FormulaImpl(std::string text, Sheet& sheet)
        : text_(std::move(text))
        , sheet_(sheet) {
        try {
            formula_ = ParseFormula(text_);
        } catch (const std::exception& exc) {
            std::throw_with_nested(FormulaException(exc.what()));
        }
    }

    Value GetValue(const Sheet& sheet) const override {
        FormulaInterface::Value val = formula_.get()->Evaluate(sheet);
        if (std::holds_alternative<FormulaError>(val)) {
            return std::get<FormulaError>(val);
        }
        return std::get<double>(val);
    }

    std::string GetText() const override {
        return "=" + formula_.get()->GetExpression();
    }

    std::vector<Position> GetReferencedCells() const override {
        return formula_->GetReferencedCells();;
    }

private:
    std::string text_;
    Sheet& sheet_;
    std::unique_ptr<FormulaInterface> formula_;
};

bool Cell::CheckCellForCyclicDependencies(const Cell* cell) const {
    if (cell == this) {
        return true;
    }

    for (const Position& pos : cell->GetReferencedCells()) {
        Cell* cell = static_cast<Cell*>(sheet_.GetCell(pos));
        if (CheckCellForCyclicDependencies(cell)) {
            return true;
        }
    }
    return false;
}

bool Cell::IsCircularDependency(const std::unique_ptr<Impl>& tmp_impl) const {
    for (const Position& pos : tmp_impl->GetReferencedCells()) {
        Cell* cell = static_cast<Cell*>(sheet_.GetCell(pos));
        if (cell == this) {
            return true;
        } else if (CheckCellForCyclicDependencies(cell)) {
            return true;
        }
    }
    return false;
}

void Cell::CacheInvalidate() {
    value_cache_.reset();
    for (auto dependent_cell : dependent_cells_) {
        dependent_cell->CacheInvalidate();
    }
}

Cell::Cell(Sheet& sheet)
    : sheet_(sheet),
    impl_(std::make_unique<EmptyImpl>()) {
}

Cell::~Cell() {}

void Cell::Set(std::string text) {
    using namespace std::literals;

    std::unique_ptr<Impl> tmp_impl;
    if (text.empty()) {
        tmp_impl = std::make_unique<EmptyImpl>();
    } else if (text.size() > 1 && text.front() == FORMULA_SIGN) {
        tmp_impl = std::make_unique<FormulaImpl>(std::move(text.substr(1)), sheet_);
    } else {
        tmp_impl = std::make_unique<TextImpl>(std::move(text));
    }

    for (const Position& pos : tmp_impl->GetReferencedCells()) {
        Cell* cell = static_cast<Cell*>(sheet_.GetCell(pos));
        if (!cell) {
            sheet_.SetCell(pos, "");
        }

        static_cast<Cell*>(sheet_.GetCell(pos))->dependent_cells_.insert(this);
    }

    if (IsCircularDependency(tmp_impl)) {
        throw CircularDependencyException("The new value of the cell \"" + tmp_impl->GetText() +
                                           "\" creates a cyclic dependency"s);
    }

    impl_ = std::move(tmp_impl);

    CacheInvalidate();
}

void Cell::Clear() {
    impl_ = std::make_unique<EmptyImpl>();
    CacheInvalidate();
}

Cell::Value Cell::GetValue() const {
    if (!value_cache_) {
        value_cache_ = impl_->GetValue(sheet_);
    }
    return value_cache_.value();
}

std::string Cell::GetText() const {
    return impl_->GetText();
}

std::vector<Position> Cell::GetReferencedCells() const {
    return impl_->GetReferencedCells();
}