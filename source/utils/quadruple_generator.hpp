#include <fstream>
#include "utils.hpp"
#include "symbol_table.hpp"
#include "enums.hpp"


class quadruple_generator {
    fstream writer;
    void write_quadruple(ops operation, symbol *op1, symbol *op2, symbol *dst);
    void write_quadruple(ops operation, string op1_str, string op2_str, string dst_str);
public:
    quadruple_generator(string filename);
    // these print conversion quadruples to file
    // assuming the input op is convertible to this type
    // otherwise it throws a yyerror
    void Int(symbol* op);
    void Double(symbol* op);
    void String(symbol* op);
    void Bool(symbol* op);
    void Numeric(symbol* op1,symbol* op2);
    void BitAccessable(symbol* op1, symbol* op2);

    void assign_op(symbol* dst, symbol* src);
    symbol* not_op(symbol* op);
    symbol* binary_logical_op(ops operation , symbol* op1 , symbol* op2);
    symbol* binary_bitwise_op(ops operation , symbol* op1 , symbol* op2);
    symbol* arth_op(ops operation , symbol* op1 , symbol* op2);
    symbol* plus_op(symbol* op1 , symbol* op2);
    symbol* concat_op(symbol* op1 , symbol* op2);
    symbol* relational_op(ops operation , symbol* op1 , symbol* op2);
    void jmp_on_condition(symbol* op , bool on_true , string label);
    void jmp_unconditional(string label);
    void push(symbol *op);
    symbol* pop(symbol *op);
    ~quadruple_generator();
};

