//
// Project: CMiniLang
// Author: bajdcc
//

#include <cassert>
#include <cstring>
#include "types.h"

namespace clib {
    std::tuple<lexer_t, string_t, int> lexer_string_list[] = {
        std::make_tuple(l_none,         "none",         0),
        std::make_tuple(l_error,        "error",        0),
        std::make_tuple(l_char,         "char",         1),
        std::make_tuple(l_uchar,        "uchar",        2),
        std::make_tuple(l_short,        "short",        3),
        std::make_tuple(l_ushort,       "ushort",       4),
        std::make_tuple(l_int,          "int",          5),
        std::make_tuple(l_uint,         "uint",         6),
        std::make_tuple(l_long,         "long",         7),
        std::make_tuple(l_ulong,        "ulong",        8),
        std::make_tuple(l_float,        "float",        9),
        std::make_tuple(l_double,       "double",       10),
        std::make_tuple(l_operator,     "operator",     0),
        std::make_tuple(l_keyword,      "keyword",      0),
        std::make_tuple(l_identifier,   "identifier",   0),
        std::make_tuple(l_string,       "string",       0),
        std::make_tuple(l_comment,      "comment",      0),
        std::make_tuple(l_space,        "space",        0),
        std::make_tuple(l_newline,      "newline",      0),
        std::make_tuple(l_end,          "EOF",          0),
    };

    const string_t &lexer_typestr(lexer_t type) {
        assert(type >= l_none && type <= l_end);
        return std::get<1>(lexer_string_list[type]);
    }

    int lexer_prior(lexer_t type) {
        assert(type >= l_none && type <= l_end);
        return std::get<2>(lexer_string_list[type]);
    }

    std::tuple<keyword_t, string_t> keyword_string_list[] = {
        std::make_tuple(k__start, "@START"),
        std::make_tuple(k_auto, "auto"),
        std::make_tuple(k_bool, "bool"),
        std::make_tuple(k_break, "break"),
        std::make_tuple(k_case, "case"),
        std::make_tuple(k_char, "char"),
        std::make_tuple(k_const, "const"),
        std::make_tuple(k_continue, "continue"),
        std::make_tuple(k_default, "default"),
        std::make_tuple(k_do, "do"),
        std::make_tuple(k_double, "double"),
        std::make_tuple(k_else, "else"),
        std::make_tuple(k_enum, "enum"),
        std::make_tuple(k_extern, "extern"),
        std::make_tuple(k_false, "false"),
        std::make_tuple(k_float, "float"),
        std::make_tuple(k_for, "for"),
        std::make_tuple(k_goto, "goto"),
        std::make_tuple(k_if, "if"),
        std::make_tuple(k_int, "int"),
        std::make_tuple(k_long, "long"),
        std::make_tuple(k_register, "register"),
        std::make_tuple(k_return, "return"),
        std::make_tuple(k_short, "short"),
        std::make_tuple(k_signed, "signed"),
        std::make_tuple(k_sizeof, "sizeof"),
        std::make_tuple(k_static, "static"),
        std::make_tuple(k_struct, "struct"),
        std::make_tuple(k_switch, "switch"),
        std::make_tuple(k_true, "true"),
        std::make_tuple(k_typedef, "typedef"),
        std::make_tuple(k_union, "union"),
        std::make_tuple(k_unsigned, "unsigned"),
        std::make_tuple(k_void, "void"),
        std::make_tuple(k_volatile, "volatile"),
        std::make_tuple(k_while, "while"),
        std::make_tuple(k__end, "@END"),
    };

    const string_t &lexer_keywordstr(keyword_t type) {
        assert(type > k__start && type < k__end);
        return std::get<1>(keyword_string_list[type - k__start]);
    }

    std::tuple<operator_t, string_t, string_t, ins_t, int> operator_string_list[] = {
        std::make_tuple(op__start, "@START", "@START", NOP, 9999),
        std::make_tuple(op_assign, "=", "assign", NOP, 1401),
        std::make_tuple(op_equal, "==", "equal", EQ, 701),
        std::make_tuple(op_plus, "+", "plus", ADD, 401),
        std::make_tuple(op_plus_assign, "+=", "plus_assign", ADD, 1405),
        std::make_tuple(op_minus, "-", "minus", SUB, 402),
        std::make_tuple(op_minus_assign, "-=", "minus_assign", SUB, 1406),
        std::make_tuple(op_times, "*", "times", MUL, 302),
        std::make_tuple(op_times_assign, "*=", "times_assign", MUL, 1403),
        std::make_tuple(op_divide, "/", "divide", DIV, 301),
        std::make_tuple(op_div_assign, "/=", "div_assign", DIV, 1402),
        std::make_tuple(op_bit_and, "&", "bit_and", AND, 801),
        std::make_tuple(op_and_assign, "&=", "and_assign", AND, 1409),
        std::make_tuple(op_bit_or, "|", "bit_or", OR, 1001),
        std::make_tuple(op_or_assign, "|=", "or_assign", OR, 1411),
        std::make_tuple(op_bit_xor, "^", "bit_xor", XOR, 901),
        std::make_tuple(op_xor_assign, "^=", "xor_assign", XOR, 1410),
        std::make_tuple(op_mod, "%", "mod", MOD, 303),
        std::make_tuple(op_mod_assign, "%=", "mod_assign", MOD, 1404),
        std::make_tuple(op_less_than, "<", "less_than", LT, 603),
        std::make_tuple(op_less_than_or_equal, "<=", "less_than_or_equal", LE, 604),
        std::make_tuple(op_greater_than, ">", "greater_than", GT, 601),
        std::make_tuple(op_greater_than_or_equal, ">=", "greater_than_or_equal", GE, 602),
        std::make_tuple(op_logical_not, "!", "logical_not", NOP, 207),
        std::make_tuple(op_not_equal, "!=", "not_equal", NE, 702),
        std::make_tuple(op_escape, "\\", "escape", NOP, 9000),
        std::make_tuple(op_query, "?", "query", NOP, 1301),
        std::make_tuple(op_bit_not, "~", "bit_not", NOP, 208),
        std::make_tuple(op_lparan, "(", "lparan", NOP, 102),
        std::make_tuple(op_rparan, ")", "rparan", NOP, 102),
        std::make_tuple(op_lbrace, "{", "lbrace", NOP, 9000),
        std::make_tuple(op_rbrace, "}", "rbrace", NOP, 9000),
        std::make_tuple(op_lsquare, "[", "lsquare", NOP, 101),
        std::make_tuple(op_rsquare, "]", "rsquare", NOP, 101),
        std::make_tuple(op_comma, ",", "comma", NOP, 1501),
        std::make_tuple(op_dot, ".", "dot", NOP, 103),
        std::make_tuple(op_semi, ";", "semi", NOP, 9000),
        std::make_tuple(op_colon, ":", "colon", NOP, 1302),
        std::make_tuple(op_plus_plus, "++", "plus_plus", ADD, 203),
        std::make_tuple(op_minus_minus, "--", "minus_minus", SUB, 204),
        std::make_tuple(op_logical_and, "&&", "logical_and", JZ, 1101),
        std::make_tuple(op_logical_or, "||", "logical_or", JNZ, 1201),
        std::make_tuple(op_pointer, "->", "pointer", NOP, 104),
        std::make_tuple(op_left_shift, "<<", "left_shift", SHL, 501),
        std::make_tuple(op_right_shift, ">>", "right_shift", SHR, 502),
        std::make_tuple(op_left_shift_assign, "<<=", "left_shift_assign", SHL, 1407),
        std::make_tuple(op_right_shift_assign, ">>=", "right_shift_assign", SHR, 1408),
        std::make_tuple(op_ellipsis, "...", "ellipsis", NOP, 9000),
        std::make_tuple(op_quote, "`", "quote", NOP, 9000),
        std::make_tuple(op__end, "@END", "@END", NOP, 9999),
    };

    const string_t &lexer_opstr(operator_t type) {
        assert(type > op__start && type <= op__end);
        return std::get<1>(operator_string_list[type]);
    }

    const string_t &lexer_opnamestr(operator_t type) {
        assert(type > op__start && type <= op__end);
        return std::get<2>(operator_string_list[type]);
    }

    string_t err_string_list[] = {
        "@START",
        "#E !char!",
        "#E !operator!",
        "#E !digit!",
        "#E !string!",
        "@END",
    };

    const string_t &lexer_errstr(error_t type) {
        assert(type > e__start && type < e__end);
        return err_string_list[type];
    }

    int lexer_operatorpred(operator_t type) {
        assert(type > op__start && type < op__end);
        return std::get<4>(operator_string_list[type]);
    }

    int lexer_op2ins(operator_t type) {
        assert(type > op__start && type < op__end);
        return std::get<3>(operator_string_list[type]);
    }

    std::tuple<coll_t, string_t> coll_string_list[] = {
        std::make_tuple(c_program, "program"),
        std::make_tuple(c_list, "list"),
        std::make_tuple(c_sexpr, "sexpr"),
        std::make_tuple(c_qexpr, "qexpr"),
        std::make_tuple(c_object, "object"),
    };

    const string_t &coll_str(coll_t t) {
        assert(t >= c_program && t <= c_object);
        return std::get<1>(coll_string_list[t]);
    }
}
