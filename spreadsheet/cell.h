#pragma once

#include "common.h"
#include "formula.h"

#include <optional>
#include <unordered_set>

class Cell : public CellInterface {
public:
    Cell(SheetInterface& sheet);
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

    SheetInterface& sheet_;
    std::unique_ptr<Impl> impl_;

    std::unordered_set<Cell*> dependent_cells_;
    mutable std::optional<Value> value_cache_;

    enum class Update {
        ADD,
        REMOVE
    };

    void CheckCellForCyclicDependencies(const CellInterface* cell) const;
    void SearchForCyclicDependencies(const std::unique_ptr<FormulaImpl>& impl) const;

    void CacheReset();

    void UpdateDependecies(Update upd);
};