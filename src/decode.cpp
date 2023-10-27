#include "tiny-parrot.hpp"

bool    decode_addi(std::string instr)
{
    std::stringstream operands(instr.substr(instr.find(" ") + 1));
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
    std::cout << rd << " " << rs1 << " " << imm << std::endl;
    return true;
}

bool    decode(std::string instr)
{
    std::cout << instr << std::endl;
    std::string opcode = instr.substr(0, instr.find(" "));
    std::cout << opcode << std::endl;
    if (!opcode.compare("addi"))
        return decode_addi(instr);

    return (true);
}