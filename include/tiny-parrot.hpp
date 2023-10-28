#ifndef TINY_PARROT_HPP
# define TINY_PARROT_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <sstream>
# include <algorithm>
# include "register.hpp"

# include <unordered_set>
enum class instr_type
{
    R_type,
    I_type,
    S_type,
    B_type,
    U_type,
    J_type,
    NOP
};

// format.cpp
instr_type get_format(std::string opcode);

// decode.cpp
bool decode(std::string instr);

// execute.cpp
bool execute_i_type(std::string imm, std::string rs1, std::string rd, std::string opcode);
bool execute_r_type(std::string rs2, std::string rs1, std::string rd, std::string opcode);

#endif