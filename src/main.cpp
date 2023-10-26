#include "tiny-parrot.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "usage: tiny-parrot [file]" << std::endl;
        return (1);
    }
    std::cout << "hello from RV32I!" << std::endl;

    std::ifstream file(argv[1]);
    std::string instr;
    while (std::getline(file, instr))
    {
        std::cout << instr << std::endl;
        std::string opcode = instr.substr(0, instr.find(" "));
        std::cout << opcode << std::endl;
        std::stringstream operands = static_cast<std::stringstream>(&instr[instr.find(" ")]);
        std::string opr;
        while (getline(operands, opr, ','))
        {
            opr.erase(std::remove(opr.begin(), opr.end(), ' '), opr.end());
            std::cout << opr << std::endl;
        }
        std::cout << "--------------" << std::endl;
    }
}