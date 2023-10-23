#include "sheet.h"

#include <algorithm>
#include <functional>
#include <iostream>
#include <optional>

using namespace std::literals;

void Sheet::CheckValidityOfPosition(Position pos) const {
    if (!pos.IsValid()) {
        throw InvalidPositionException("Invalid position");
    }
}

void Sheet::CheckForCyclicDependencies(Position pos, std::vector<Position> list_cells) {
    for (Position pos_cell : list_cells) {
        if (pos == pos_cell) {
            throw CircularDependencyException("Cyclic dependency");
        }
    }
}

Sheet::~Sheet() {
    for (auto& cell : sheet_) {
        cell.second.reset();
    }
}

void Sheet::SetCell(Position pos, std::string text) {
    CheckValidityOfPosition(pos);
    if (sheet_.count(pos) > 0) {
        sheet_[pos]->Set(text);
    } else {
        std::unique_ptr<Cell> cell = std::make_unique<Cell>(*this);
        cell->Set(text);
        sheet_[pos] = std::move(cell);
    }
    CheckForCyclicDependencies(pos, sheet_.at(pos).get()->GetReferencedCells());
}

const CellInterface* Sheet::GetCell(Position pos) const {
    CheckValidityOfPosition(pos);
    if (sheet_.count(pos) > 0) {
        return sheet_.at(pos).get();
    } else {
        return nullptr;
    }
}

CellInterface* Sheet::GetCell(Position pos) {
    CheckValidityOfPosition(pos);
    if (sheet_.count(pos) > 0) {
        return sheet_.at(pos).get();
    } else {
        return nullptr;
    }
}

void Sheet::ClearCell(Position pos) {
    CheckValidityOfPosition(pos);
    if (sheet_.count(pos) > 0) {
        sheet_.erase(pos);
    }
}

Size Sheet::GetPrintableSize() const {
    Size printable_size{0, 0};
    for (const auto& cell : sheet_) {
        const Position& pos = cell.first;
        printable_size.cols = std::max(printable_size.cols, pos.col + 1);
        printable_size.rows = std::max(printable_size.rows, pos.row + 1);
    }
    return printable_size;
}

void Sheet::PrintValues(std::ostream& output) const {
    Size printable_size = GetPrintableSize();
    for (int row = 0; row < printable_size.rows; ++row) {
        for (int col = 0; col < printable_size.cols; ++col) {
            Position pos {row, col};
            const CellInterface* cell = GetCell(pos);
            if (cell) {
                CellInterface::Value val = cell->GetValue();
                if (std::holds_alternative<std::string>(val)) {
                    output << std::get<std::string>(val);
                } else if (std::holds_alternative<double>(val)) {
                    output << std::get<double>(val);
                } else if (std::holds_alternative<FormulaError>(val)) {
                    output << std::get<FormulaError>(val);
                }
            }
            if (col < (printable_size.cols - 1)) {
                output << '\t';
            }
        }
        output << '\n';
    }
}

void Sheet::PrintTexts(std::ostream& output) const {
    Size printable_size = GetPrintableSize();
    for (int row = 0; row < printable_size.rows; ++row) {
        for (int col = 0; col < printable_size.cols; ++col) {
            Position pos {row, col};
            const CellInterface* cell = GetCell(pos);
            if (cell) {
                output << cell->GetText();
            }
            if (col < (printable_size.cols - 1)) {
                output << '\t';
            }
        }
        output << '\n';
    }
}

std::unique_ptr<SheetInterface> CreateSheet() {
    return std::make_unique<Sheet>();
}