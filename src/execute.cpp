#include "tiny-parrot.hpp"

extern Register regs;
extern DataMemory datamem;

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
        regs.pc = regs.read(rs1) + (stoi(imm) * 4) - 4; // -4 then it will be added after in main loop.
        regs.write(rd, regs.pc + 4);  // if rd is not specified, pc + 4 is restored in x1.
    }
    else if (!opcode.compare("lw"))
        regs.write(rd, datamem.read_memory(4, regs.read(rs1) + (int32_t)stoi(imm)));
    else if (!opcode.compare("lh"))
        regs.write(rd, datamem.read_memory(2, regs.read(rs1) + (int32_t)stoi(imm)));
    else if (!opcode.compare("lb"))
        regs.write(rd, datamem.read_memory(1, regs.read(rs1) + (int32_t)stoi(imm)));
    else if (!opcode.compare("lhu"))
        regs.write(rd, (uint32_t)datamem.read_memory(2, regs.read(rs1) + (int32_t)stoi(imm)));
    else if (!opcode.compare("lbu"))
        regs.write(rd, (uint32_t)datamem.read_memory(1, regs.read(rs1) + (int32_t)stoi(imm)));
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
            regs.pc += (stoi(offset) * 4) - 4; // -4 then it will be added after in main
        // regs.pc = regs.read(rs1) == regs.read(rs2) ? regs.pc += offset : regs.pc;
    }
    else if (!opcode.compare("bne"))
    {
        if (regs.read(rs1) != regs.read(rs2))
            regs.pc += (stoi(offset) * 4) - 4; // -4 then it will be added after in main loop.
        // regs.pc = regs.read(rs1) != regs.read(rs2) ? regs.pc += offset : regs.pc;
    }
    else if (!opcode.compare("blt"))
    {
        if (regs.read(rs1) < regs.read(rs2))
            regs.pc += (stoi(offset) * 4) - 4; // -4 then it will be added after in main loop.
    }
    else if (!opcode.compare("bge"))
    {
        if (regs.read(rs1) >= regs.read(rs2))
            regs.pc += (stoi(offset) * 4) - 4; // -4 then it will be added after in main loop.
    }
    else if (!opcode.compare("bltu"))
    {
        if ((uint32_t)regs.read(rs1) < (uint32_t)regs.read(rs2))
            regs.pc += (stoi(offset) * 4) - 4; // -4 then it will be added after in main loop.
    }
    else if (!opcode.compare("bgeu"))
    {
        if ((uint32_t)regs.read(rs1) >= (uint32_t)regs.read(rs2))
            regs.pc += (stoi(offset) * 4) - 4; // -4 then it will be added after in main loop.
    }
    return true;
}

bool execute_j_type(std::string offset, std::string rd, std::string opcode)
{
    if (!opcode.compare("jal"))
    {
        regs.write(rd, regs.pc + 4); // if rd is not specified, pc + 4 is restored in x1.
        regs.pc += (stoi(offset) * 4) - 4; // -4 then it will be added after in main loop.
    }
    return true;
}

bool execute_s_type(std::string offset, std::string rs2, std::string rs1, std::string opcode)
{
    if (!opcode.compare("sw"))
    {
        // sw, rs1, rs2, offset -> mem[rs2 + offset] = rs1
        std::cout << "rs1:" << regs.read(rs1) << std::endl;
        std::cout << "rs2:" << regs.read(rs2) << std::endl;
        std::cout << "offset:" << stoi(offset) << std::endl;
        std::cout << regs.read(rs1) + (int32_t)stoi(offset) << std::endl;
        datamem.write_memory(regs.read(rs1), regs.read(rs2) + (int32_t)stoi(offset));
    }
    else if (!opcode.compare("sh"))
    {
        // sh, rs1, rs2, offset -> mem[rs2 + offset] = rs1
        datamem.write_memory(regs.read(rs1) & 0x0000ffff, regs.read(rs2) + (int32_t)stoi(offset));
    }
    else if (!opcode.compare("sb"))
    {
        // sb, rs1, rs2, offset -> mem[rs2 + offset] = rs1
        datamem.write_memory(regs.read(rs1) & 0x000000ff, regs.read(rs2) + (int32_t)stoi(offset));
    }
    return true;
}