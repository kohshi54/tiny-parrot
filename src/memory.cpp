#include "memory.hpp"

void InstrMemory::load_program(std::ifstream &file)
{
    std::string instr;

    while (std::getline(file, instr))
    {
        this->instr_memory.push_back(instr);
    }
}