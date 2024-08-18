#pragma once

#include <variant>
#include "literal.hpp"
#include "any.hpp"

namespace parser
{
    struct variant_visitor
    {
        virtual std::string operator()(int arg) const = 0;
        virtual std::string operator()(bool arg) const = 0;
    };

    struct variant_ast_printer
        : public variant_visitor
    {
        std::string operator()(int arg) const;
        std::string operator()(bool arg) const;
    };

    struct variant_mapper
        : public variant_visitor
    {
        std::string operator()(int arg) const;
        std::string operator()(bool arg) const;
    };

    struct variant
        : public literal<any>
    {
        variant(any value);
        ~variant();

        parser::any accept(const interpreter::visitor *visitor) const;
        std::string to_string() const;
    };

} // namespace parser
