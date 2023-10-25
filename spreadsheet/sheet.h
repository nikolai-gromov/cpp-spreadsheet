#pragma once

#include "cell.h"
#include "common.h"

#include <functional>

class Cell;

template <typename P>
struct Hash {
    size_t operator()(const P& pos) const {
        return std::hash<int>()(pos.row) ^ std::hash<int>()(pos.col);
    }
};

class Sheet : public SheetInterface {
public:
    ~Sheet();

    void SetCell(Position pos, std::string text) override;

    const CellInterface* GetCell(Position pos) const override;
    CellInterface* GetCell(Position pos) override;

    void ClearCell(Position pos) override;

    Size GetPrintableSize() const override;

    void PrintValues(std::ostream& output) const override;
    void PrintTexts(std::ostream& output) const override;

private:
	std::unordered_map<Position, std::unique_ptr<Cell>, Hash<Position>> sheet_;

    void CheckValidityOfPosition(Position pos) const;
};