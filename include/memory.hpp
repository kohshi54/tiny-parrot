#ifndef MEMORY_HPP
# define MEMORY_HPP

# include <iostream>
# include <vector>
# include <fstream>
# include <iostream>

class InstrMemory
{
    public:
        std::vector<std::string> instr_memory;
        void load_program(std::ifstream &file);
};

#endif