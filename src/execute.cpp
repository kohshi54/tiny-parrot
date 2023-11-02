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
    else if (!opcode.compare("slli")) // cast rs1 to (uint 32) from (int 32) in order to make shift logical and not cause sign extension.
        regs.write(rd, (uint32_t)regs.read(rs1) << stoi(imm));
    else if (!opcode.compare("srai"))
        regs.write(rd, regs.read(rs1) >> stoi(imm));
    else if (!opcode.compare("srli")) // cast rs1 to (uint 32) from (int 32) in order to make shift logical and not cause sign extension.
        regs.write(rd, (uint32_t)regs.read(rs1) >> stoi(imm));
    else if (!opcode.compare("slti"))
        regs.write(rd, regs.read(rs1) < stoi(imm));
    else if (!opcode.compare("sltiu"))
        regs.write(rd, (uint32_t)regs.read(rs1) < (uint32_t)stoi(imm));
    else if (!opcode.compare("jalr"))
    {
        regs.pc = regs.read(rs1) + stoi(imm) - 4; // -4 then it will be added after in main loop.
        regs.write(rd, regs.pc + 4);
        std::cout << "rd: " << regs.read(rd) << std::endl;
    }
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
    else if (!opcode.compare("sll")) // cast rs1 to (uint 32) from (int 32) in order to make shift logical and not cause sign extension.
        regs.write(rd, (uint32_t)regs.read(rs1) << regs.read(rs2));
    else if (!opcode.compare("sra"))
        regs.write(rd, regs.read(rs1) >> regs.read(rs2));
    else if (!opcode.compare("srl")) // cast rs1 to (uint 32) from (int 32) in order to make shift logical and not cause sign extension.
        regs.write(rd, (uint32_t)regs.read(rs1) >> regs.read(rs2));
    else if (!opcode.compare("slt"))
        regs.write(rd, regs.read(rs1) < regs.read(rs2));
    else if (!opcode.compare("sltu"))
        regs.write(rd, (uint32_t)regs.read(rs1) < (uint32_t)regs.read(rs2));
    return true;
}

bool execute_u_type(std::string imm, std::string rd, std::string opcode)
{
    if (!opcode.compare("lui"))
        regs.write(rd, (int32_t)stoi(imm) << 12); // sign extension and then shift left 12 bits.
    else if (!opcode.compare("auipc"))
        regs.write(rd, regs.pc + ((int32_t)stoi(imm) << 12)); // sign extension and then shift left 12 bits.
    return true;
}

bool execute_b_type(std::string offset, std::string rs2, std::string rs1, std::string opcode)
{
    if (!opcode.compare("beq"))
    {
        if (regs.read(rs1) == regs.read(rs2))
            regs.pc += (stoi(offset) - 4); // -4 then it will be added after in main
        // regs.pc = regs.read(rs1) == regs.read(rs2) ? regs.pc += offset : regs.pc;
    }
    else if (!opcode.compare("bne"))
    {
        if (regs.read(rs1) != regs.read(rs2))
            regs.pc += (stoi(offset) - 4); // -4 then it will be added after in main loop.
        // regs.pc = regs.read(rs1) != regs.read(rs2) ? regs.pc += offset : regs.pc;
    }
    else if (!opcode.compare("blt"))
    {
        if (regs.read(rs1) < regs.read(rs2))
            regs.pc += (stoi(offset) - 4); // -4 then it will be added after in main loop.
    }
    else if (!opcode.compare("bge"))
    {
        if (regs.read(rs1) >= regs.read(rs2))
            regs.pc += (stoi(offset) - 4); // -4 then it will be added after in main loop.
    }
    else if (!opcode.compare("bltu"))
    {
        if ((uint32_t)regs.read(rs1) < (uint32_t)regs.read(rs2))
            regs.pc += (stoi(offset) - 4); // -4 then it will be added after in main loop.
    }
    else if (!opcode.compare("bgeu"))
    {
        if ((uint32_t)regs.read(rs1) >= (uint32_t)regs.read(rs2))
            regs.pc += (stoi(offset) - 4); // -4 then it will be added after in main loop.
    }
    return true;
}

bool execute_j_type(std::string offset, std::string rd, std::string opcode)
{
    if (!opcode.compare("jal"))
    {
        regs.write(rd, regs.pc + 4);
        regs.pc += stoi(offset) - 4; // -4 then it will be added after in main loop.
    }
    return true;
}