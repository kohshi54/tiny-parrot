#include "tiny-parrot.hpp"

extern Register regs;

bool decode_i_type(std::string &opcode, std::stringstream &operands)
{
    std::string rd, rs1, imm;
    std::string *reg[] = {&rd, &rs1, &imm};
#ifdef DEBUG
    std::cout << "rd=" << rd << ":" << regs.read(rd) << std::endl;
    std::cout << "rs1=" << rs1 << ":" << regs.read(rs1) << std::endl;
    std::cout << "imm=" << imm << std::endl;
    std::cout << "------------" << std::endl;
#endif
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
#ifdef DEBUG
    std::cout << "rd=" << rd << ":" << regs.read(rd) << std::endl;
    std::cout << "rs1=" << rs1 << ":" << regs.read(rs1) << std::endl;
    std::cout << "imm=" << imm << std::endl;
#endif
    return true;
}

bool decode_r_type(std::string &opcode, std::stringstream &operands)
{
    std::string rd, rs1, rs2;
    std::string *reg[] = {&rd, &rs1, &rs2};
#ifdef DEBUG
    std::cout << "rd=" << rd << ":" << regs.read(rd) << std::endl;
    std::cout << "rs1=" << rs1 << ":" << regs.read(rs1) << std::endl;
    std::cout << "rs2=" << rs2 << ":" << regs.read(rs2) << std::endl;
    std::cout << "------------" << std::endl;
#endif
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
#ifdef DEBUG
    std::cout << "rd=" << rd << ":" << regs.read(rd) << std::endl;
    std::cout << "rs1=" << rs1 << ":" << regs.read(rs1) << std::endl;
    std::cout << "rs2=" << rs2 << ":" << regs.read(rs2) << std::endl;
#endif
    return true;
}

bool decode_u_type(std::string &opcode, std::stringstream &operands)
{
    std::string rd, imm;
    std::string *reg[] = {&rd, &imm};
#ifdef DEBUG
    std::cout << "rd=" << rd << ":" << regs.read(rd) << std::endl;
    std::cout << "imm=" << imm << std::endl;
    std::cout << "------------" << std::endl;
#endif
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
#ifdef DEBUG
    std::cout << "rd=" << rd << ":" << regs.read(rd) << std::endl;
    std::cout << "imm=" << imm << std::endl;
#endif
    return true;
}

bool decode_b_type(std::string &opcode, std::stringstream &operands)
{
    std::string rs1, rs2, offset;
    std::string *reg[] = {&rs1, &rs2, &offset};
#ifdef DEBUG
    std::cout << "rs1=" << rs1 << ":" << regs.read(rs1) << std::endl;
    std::cout << "rs2=" << rs2 << ":" << regs.read(rs2) << std::endl;
    std::cout << "offset" << offset << std::endl;
    std::cout << "------------" << std::endl;
#endif
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
#ifdef DEBUG
    std::cout << "rs1=" << rs1 << ":" << regs.read(rs1) << std::endl;
    std::cout << "rs2=" << rs2 << ":" << regs.read(rs2) << std::endl;
    std::cout << "offset" << offset << std::endl;
#endif
    return true;
}

bool decode_j_type(std::string &opcode, std::stringstream &operands)
{
    std::string rd, offset;
    std::string *reg[] = {&rd, &offset};
#ifdef DEBUG
    std::cout << "rd=" << rd << ":" << regs.read(rd) << std::endl;
    std::cout << "offset=" << offset << std::endl;
    std::cout << "------------" << std::endl;
#endif
    for (int i = 0; i < 2; ++i)
    {
        getline(operands, *reg[i], ',');
        if (operands.eof() && i != 1)
        {
            std::cout << "invalid oprand in jal" << std::endl;
            return false;
        }
        reg[i]->erase(std::remove(reg[i]->begin(), reg[i]->end(), ' '), reg[i]->end());
    }
    execute_j_type(offset, rd, opcode);
#ifdef DEBUG
    std::cout << "rd=" << rd << ":" << regs.read(rd) << std::endl;
    std::cout << "offset=" << offset << std::endl;
#endif
    return true;
}

bool decode_s_type(std::string &opcode, std::stringstream &operands)
{
    std::string rs1, rs2, offset;
    std::string *reg[] = {&rs1, &rs2, &offset};
#ifdef DEBUG
    std::cout << "rs1=" << rs1 << ":" << regs.read(rs1) << std::endl;
    std::cout << "rs2=" << rs2 << ":" << regs.read(rs2) << std::endl;
    std::cout << "offset=" << offset << std::endl;
    std::cout << "------------" << std::endl;
#endif
    for (int i = 0; i < 3; ++i)
    {
        getline(operands, *reg[i], ',');
        if (operands.eof() && i != 2)
        {
            std::cout << "invalid oprand in sw" << std::endl;
            return false;
        }
        reg[i]->erase(std::remove(reg[i]->begin(), reg[i]->end(), ' '), reg[i]->end());
    }
    execute_s_type(offset, rs2, rs1, opcode);
#ifdef DEBUG
    std::cout << "rs1=" << rs1 << ":" << regs.read(rs1) << std::endl;
    std::cout << "rs2=" << rs2 << ":" << regs.read(rs2) << std::endl;
    std::cout << "offset=" << offset << std::endl;
#endif
    return true;
}

bool decode(std::string instr)
{
    std::string opcode = instr.substr(0, instr.find(" "));
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
            break ;
        case instr_type::B_type:
            decode_b_type(opcode, operands);
            break ;
        case instr_type::J_type:
            decode_j_type(opcode, operands);
            break ;
        case instr_type::S_type:
            decode_s_type(opcode, operands);
            break ;
        default:
            std::cout << "No such instruction: " << opcode << std::endl;
            exit(1);
            break ;
    }

    return (true);
}