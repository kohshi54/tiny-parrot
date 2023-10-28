#include "tiny-parrot.hpp"

extern Register regs;

bool execute_i_type(std::string imm, std::string rs1, std::string rd, std::string opcode)
{
    if (!opcode.compare("addi"))
        regs.write(rd, regs.read(rs1) + stoi(imm));
    return true;
}

bool execute_r_type(std::string rs2, std::string rs1, std::string rd, std::string opcode)
{
    if (!opcode.compare("add"))
        regs.write(rd, regs.read(rs1) + regs.read(rs2));
    return true;
}