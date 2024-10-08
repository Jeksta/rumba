#include "call_expression.hpp"

parser::call_expression::
    call_expression(lexer::token identifier,
                    parser::unique_expr parameter)
                    : identifier(identifier), parameter(std::move(parameter))
{
}

parser::call_expression::
    ~call_expression()
{
}

void parser::call_expression::
    accept(interpreter::expression_visitor *visitor)
{
    visitor->visit(this);
}

std::string parser::call_expression::
    to_string() const
{
    std::string parameter_str(parameter->to_string());

    std::vector<std::string> str({
        "call",
        identifier.literal,
        "with",
        parameter_str,
    });
    return std::parenthesize(str, " ", std::bracket::Square);
}