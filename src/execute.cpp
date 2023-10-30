#include "tiny-parrot.hpp"

extern Register regs;

bool execute_i_type(std::string imm, std::string rs1, std::string rd, std::string opcode)
{
    if (!opcode.compare("addi"))
        regs.write(rd, regs.read(rs1) + stoi(imm));
    else if (!opcode.compare("andi"))
        regs.write(rd, regs.read(rs1) & stoi(imm));
    else if (!opcode.compare("ori"))
        regs.write(rd, regs.read(rs1) | stoi(imm));
    else if (!opcode.compare("xori"))
        regs.write(rd, regs.read(rs1) ^ stoi(imm));

    return true;
}

bool execute_r_type(std::string rs2, std::string rs1, std::string rd, std::string opcode)
{
    if (!opcode.compare("add"))
        regs.write(rd, regs.read(rs1) + regs.read(rs2));
    else if (!opcode.compare("sub"))
        regs.write(rd, regs.read(rs1) - regs.read(rs2));
    else if (!opcode.compare("and"))
        regs.write(rd, regs.read(rs1) & regs.read(rs2));
    else if (!opcode.compare("or"))
        regs.write(rd, regs.read(rs1) | regs.read(rs2));
    else if (!opcode.compare("xor"))
        regs.write(rd, regs.read(rs1) ^ regs.read(rs2));
    else if (!opcode.compare("sll"))
        regs.write(rd, regs.read(rs1) << regs.read(rs2));
    else if (!opcode.compare("sra")) // cast rs1 to (int 64) from (uint 32) in order to make shift arithmatic and cause sign extension.
        regs.write(rd, (int64_t)regs.read(rs1) >> regs.read(rs2));
    else if (!opcode.compare("srl"))
        regs.write(rd, regs.read(rs1) >> regs.read(rs2));
    return true;
}