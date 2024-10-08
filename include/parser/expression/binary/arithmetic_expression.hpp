#pragma once

#include "binary_expression.hpp"

namespace parser
{
    struct arithmetic_expression
        : public binary_expression
    {
        arithmetic_expression(parser::unique_expr left,
                              lexer::token arithmetic_operator,
                              parser::unique_expr right);
        ~arithmetic_expression();

        void accept(interpreter::expression_visitor *visitor);
        std::string to_string() const;
    };

} // namespace parser
