#include "tiny-parrot.hpp"

Register regs;
uint32_t pc = 0;

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
        if (!decode(instr))
        {
            std::cout << "execption occurred, abort." << std::endl;
            return (1);
        }

        std::cout << regs.read("a5") << "<<<<<<<<<<<<" << std::endl;
        std::cout << regs.read("a4") << "<<<<<<<<<<<<" << std::endl;
        std::cout << "--------------" << std::endl;
        pc += 1;
    }
    regs.dump_registers();
    std::cout << pc << std::endl;
}