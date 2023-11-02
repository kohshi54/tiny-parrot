#include "tiny-parrot.hpp"

bool is_i_type(std::string opcode)
{
    static const std::unordered_set<std::string> i_types = {"addi", "slti", "sltiu",
                                                            "andi", "ori", "xori", 
                                                            "slli", "srli", "srai",
                                                            "jalr"};
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

bool is_u_type(std::string opcode)
{
    static const std::unordered_set<std::string> u_types = {"lui", "auipc"};
    return u_types.count(opcode) > 0;
}

bool is_b_type(std::string opcode)
{
    static const std::unordered_set<std::string> b_types = {"beq", "bne", 
                                                            "blt", "bltu", 
                                                            "bge", "bgeu"};
    return b_types.count(opcode) > 0;
}

bool is_j_type(std::string opcode)
{
    static const std::unordered_set<std::string> j_types = {"jal"};
    return j_types.count(opcode) > 0;
}

instr_type get_format(std::string opcode)
{
    if (is_i_type(opcode))
        return instr_type::I_type;
    if (is_r_type(opcode))
        return instr_type::R_type;
    if (is_u_type(opcode))
        return instr_type::U_type;
    if (is_b_type(opcode))
        return instr_type::B_type;
    if (is_j_type(opcode))
        return instr_type::J_type;
    return instr_type::NOP;
}