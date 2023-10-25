#pragma once

#include "common.h"
#include "formula.h"
#include "sheet.h"

#include <optional>
#include <unordered_set>

class Sheet;

class Cell : public CellInterface {
public:
    Cell(Sheet& sheet);
    ~Cell();

    void Set(std::string text);
    void Clear();

    Value GetValue() const override;
    std::string GetText() const override;

    std::vector<Position> GetReferencedCells() const override;

private:
    class Impl;
    class EmptyImpl;
    class TextImpl;
    class FormulaImpl;

    Sheet& sheet_;
    std::unique_ptr<Impl> impl_;

    std::unordered_set<Cell*> dependent_cells_;
    mutable std::optional<Value> value_cache_;

    bool CheckCellForCyclicDependencies(const Cell* cell) const;
    bool IsCircularDependency(const std::unique_ptr<Impl>& tmp_impl) const;

    void CacheInvalidate();
};