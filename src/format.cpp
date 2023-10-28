#include "tiny-parrot.hpp"

bool is_i_type(std::string opcode)
{
    static const std::unordered_set<std::string> i_types = {"addi", "slti", 
                                                            "andi", "ori", "xori", 
                                                            "slli", "srli", "srai"};
    return i_types.count(opcode) > 0;
}

bool is_r_type(std::string opcode)
{
    static const std::unordered_set<std::string> r_types = {"add", "slt", "sltu", 
                                                            "and", "and", "or", 
                                                            "xor", "sll", "srl", 
                                                            "sub", "sra"};
    return r_types.count(opcode) > 0;
};

instr_type get_format(std::string opcode)
{
    if (is_i_type(opcode))
        return instr_type::I_type;
    if (is_r_type(opcode))
        return instr_type::R_type;
    return instr_type::NOP;
}