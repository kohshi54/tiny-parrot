#include "tiny-parrot.hpp"

extern Register regs;

bool decode_i_type(std::string &opcode, std::stringstream &operands)
{
    std::string rd, rs1, imm;
    std::string *reg[] = {&rd, &rs1, &imm};
    for (int i = 0; i < 3; ++i)
    {
        getline(operands, *reg[i], ',');
        if (operands.eof() && i != 2)
        {
            std::cout << "invalid oprand in addi" << std::endl;
            return false;
        }
        reg[i]->erase(std::remove(reg[i]->begin(), reg[i]->end(), ' '), reg[i]->end());
    }
    execute_i_type(imm, rs1, rd, opcode);
    std::cout << rd << " " << rs1 << " " << imm << std::endl;
    std::cout << rd << " = " << regs.read(rd) << std::endl;
    return true;
}

bool decode_r_type(std::string &opcode, std::stringstream &operands)
{
    std::string rd, rs1, rs2;
    std::string *reg[] = {&rd, &rs1, &rs2};
    for (int i = 0; i < 3; ++i)
    {
        getline(operands, *reg[i], ',');
        if (operands.eof() && i != 2)
        {
            std::cout << "invalid oprand in add" << std::endl;
            return false;
        }
        reg[i]->erase(std::remove(reg[i]->begin(), reg[i]->end(), ' '), reg[i]->end());
    }
    execute_r_type(rs2, rs1, rd, opcode);
    std::cout << rd << " " << rs1 << " " << rs2 << std::endl;
    std::cout << rd << " = " << regs.read(rs1) << std::endl;
    return true;
}

bool decode_u_type(std::string &opcode, std::stringstream &operands)
{
    std::string rd, imm;
    std::string *reg[] = {&rd, &imm};
    for (int i = 0; i < 2; ++i)
    {
        getline(operands, *reg[i], ',');
        if (operands.eof() && i != 1)
        {
            std::cout << "invalid oprand in lui" << std::endl;
            return false;
        }
        reg[i]->erase(std::remove(reg[i]->begin(), reg[i]->end(), ' '), reg[i]->end());
    }
    execute_u_type(imm, rd, opcode);
    std::cout << rd << " " << imm << std::endl;
    std::cout << rd << " = " << regs.read(rd) << std::endl;
    return true;
}

bool decode_b_type(std::string &opcode, std::stringstream &operands)
{
    std::string rs1, rs2, offset;
    std::string *reg[] = {&rs1, &rs2, &offset};
    for (int i = 0; i < 3; ++i)
    {
        getline(operands, *reg[i], ',');
        if (operands.eof() && i != 2)
        {
            std::cout << "invalid oprand in beq" << std::endl;
            return false;
        }
        reg[i]->erase(std::remove(reg[i]->begin(), reg[i]->end(), ' '), reg[i]->end());
    }
    execute_b_type(offset, rs2, rs1, opcode);
    return true;
}

bool decode(std::string instr)
{
    std::cout << instr << std::endl;
    std::string opcode = instr.substr(0, instr.find(" "));
    std::cout << opcode << std::endl;
    std::stringstream operands(instr.substr(instr.find(" ") + 1));
    switch (get_format(opcode))
    {
        case instr_type::I_type:
            decode_i_type(opcode, operands);
            break ;
        case instr_type::R_type:
            decode_r_type(opcode, operands);
            break ;
        case instr_type::U_type:
            decode_u_type(opcode, operands);
        case instr_type::B_type:
            decode_b_type(opcode, operands);
            break ;
        default:
            break ;
    }

    return (true);
}