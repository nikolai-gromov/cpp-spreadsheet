#include "formula.h"

#include "FormulaAST.h"

#include <algorithm>
#include <cassert>
#include <cctype>
#include <sstream>
#include <functional>

using namespace std::literals;

std::ostream& operator<<(std::ostream& output, FormulaError fe) {
    return output << fe.ToString();
}

double InterpretText(std::string str) {
    if (str.empty()) {
        return 0.;
    }
    double value = 0.;
    try {
        size_t pos = 0;
        value = std::stod(str, &pos);
        if (pos != str.size()) {
            throw FormulaError(FormulaError::Category::Value);
        }
    } catch (const std::exception&) {
        throw FormulaError(FormulaError::Category::Value);
    }
    return value;
}

namespace {
class Formula : public FormulaInterface {
public:
    explicit Formula(std::string expression) try
        : ast_(ParseFormulaAST(expression)) {
    } catch (const std::exception& exc) {
       std::throw_with_nested(FormulaException(exc.what()));
    }

    Value Evaluate(const SheetInterface& sheet) const override {
        try {
            auto display_value = [&sheet](Position pos) -> std::variant<double, FormulaError> {
                Size printable_size = sheet.GetPrintableSize();
                if (!pos.IsValid()) {
                    return FormulaError(FormulaError::Category::Ref);
                } else if (pos < Position {printable_size.rows, printable_size.cols}) {
                    const CellInterface* cell = sheet.GetCell(pos);
                    if (cell) {
                        CellInterface::Value val = cell->GetValue();
                        if (std::holds_alternative<std::string>(val)) {
                            return InterpretText(std::get<std::string>(val));
                        } else if (std::holds_alternative<double>(val)) {
                            return std::get<double>(val);
                        } else if (std::holds_alternative<FormulaError>(val)) {
                            return std::get<FormulaError>(val);
                        }
                    }
                }
                return 0.;
            };
            return ast_.Execute(display_value);
        } catch (const FormulaError& error) {
            return error;
        }
    }

    std::string GetExpression() const override {
        std::ostringstream os;
        ast_.PrintFormula(os);
        return os.str();
    }

    std::vector<Position> GetReferencedCells() const override {
        std::vector<Position> list_cells;
        for (Position pos : ast_.GetCells()) {
            if (list_cells.empty()) {
                list_cells.push_back(pos);
            } else if (list_cells.back() == pos) {
                continue;
            } else {
                list_cells.push_back(pos);
            }
        }
        return list_cells;
    }

private:
    FormulaAST ast_;

};
}  // namespace

std::unique_ptr<FormulaInterface> ParseFormula(std::string expression) {
        return std::make_unique<Formula>(std::move(expression));
}