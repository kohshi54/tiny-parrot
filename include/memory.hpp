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

class DataMemory
{
    public:
        DataMemory();
        void write_memory(int32_t data, int addr);
        int32_t read_memory(int bytes, int addr);

    private:
        static const size_t mem_size = 1024 * 1024 * 1024;
        std::vector<char> data_memory; // 1GB of memory.
};

class MemoryMappedIO
{
    public:
        const static int printaddr = 1000;
        const static int readaddr = 1001;
};

#endif