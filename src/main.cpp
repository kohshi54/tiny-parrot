#include "tiny-parrot.hpp"

Register regs;
InstrMemory instrmem;
DataMemory datamem;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "usage: tiny-parrot [file]" << std::endl;
        return (1);
    }
    std::cout << "hello from RV32I!" << std::endl;
    // set sp
    regs.write("sp", 60);
    std::ifstream file(argv[1]);
    instrmem.load_program(file);
    size_t count = 0;
    while (regs.pc / 4 < instrmem.instr_memory.size())
    {
        std::cout << "pc=" << regs.pc / 4 + 1 << " : " << instrmem.instr_memory[regs.pc / 4] << std::endl;
        if (!decode(instrmem.instr_memory[regs.pc / 4]))
        {
            std::cout << "exception occurred, abort." << std::endl;
            return (1);
        }
        regs.dump_registers();
        std::cout << "sum = " << datamem.read_memory(1,40) << std::endl;
        std::cout << "=========================" << std::endl;
        regs.pc += 4; // modify this to 4 byte alligned later. -> done.
        count++;
    }
    regs.dump_registers();
    std::cout << "sum = " << datamem.read_memory(1,40) << std::endl;
    std::cout << "num of instrs: " << count << std::endl;
}