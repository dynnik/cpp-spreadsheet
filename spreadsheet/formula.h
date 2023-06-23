#pragma once

#include <memory>
#include <vector>

#include "common.h"

class FormulaInterface
{
public:
    using Value = std::variant<double, FormulaError>;

    virtual ~FormulaInterface() = default;

    virtual Value Evaluate(const SheetInterface& sheet) const = 0; //Returns calculated formula's value(or error)

    virtual std::string GetExpression() const = 0; //Returns formula's expression(without excessive bracets and spaces)
    virtual std::vector<Position> GetReferencedCells() const = 0; //Returns list of referenced cells without dublicates
};

std::unique_ptr<FormulaInterface> ParseFormula(std::string expression); //Returns parced formula as an object(throws FormulaException if incorrect)
