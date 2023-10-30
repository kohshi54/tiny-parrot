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
        if (!decode(instr)) // modify this to read instr from instr memory based on pc.
        {
            std::cout << "exception occurred, abort." << std::endl;
            return (1);
        }

        std::cout << regs.read("a5") << "<<<<<<<<<<<<" << std::endl;
        std::cout << regs.read("a4") << "<<<<<<<<<<<<" << std::endl;
        std::cout << "--------------" << std::endl;
        pc += 1; // modify this to 4 byte alligned later.
    }
    regs.dump_registers();
    std::cout << pc << std::endl;
}