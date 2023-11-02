#include "tiny-parrot.hpp"

Register regs;
InstrMemory instrmem;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "usage: tiny-parrot [file]" << std::endl;
        return (1);
    }
    std::cout << "hello from RV32I!" << std::endl;

    std::ifstream file(argv[1]);
    instrmem.load_program(file);
    while (regs.pc / 4 < instrmem.instr_memory.size())
    {
        if (!decode(instrmem.instr_memory[regs.pc / 4]))
        {
            std::cout << "exception occurred, abort." << std::endl;
            return (1);
        }

        std::cout << regs.read("a5") << "<<<<<<<<<<<<" << std::endl;
        std::cout << regs.read("a4") << "<<<<<<<<<<<<" << std::endl;
        std::cout << "--------------" << std::endl;
        regs.pc += 4; // modify this to 4 byte alligned later. -> done.
    }
    regs.dump_registers();
    std::cout << regs.pc << std::endl;
}