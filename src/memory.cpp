#include "memory.hpp"

void InstrMemory::load_program(std::ifstream &file)
{
    std::string instr;

    while (std::getline(file, instr))
    {
        this->instr_memory.push_back(instr);
    }
}

void DataMemory::write_memory(int32_t data, int addr) // write one word (4 bytes).
{
    // addr -= 1; // use addr as index to write data to memory vector, so -1.
    // if (mem_size - 4 < static_cast<size_t>(addr))
    if (static_cast<size_t>(addr) > mem_size - 3)
    {
        std::cout << "invalid memory access to address: " << addr << std::endl;
        exit(1);
        // return ;
    }
    data_memory[addr] = static_cast<char>(data & 0xFF); // Cast to char to store only the lower byte
    data_memory[addr + 1] = static_cast<char>((data >> 8) & 0xFF); // Shift by 8 bits to get the next byte
    data_memory[addr + 2] = static_cast<char>((data >> 16) & 0xFF); // Shift by 16 bits for the third byte
    data_memory[addr + 3] = static_cast<char>((data >> 24) & 0xFF); // Shift by 24 bits for the fourth byte
}

int32_t DataMemory::read_memory(int bytes, int addr) // read num of bytes and return one word.
{
    // addr -= 1; // use addr as index to elicit data from memory vector, so -1.
    // if (mem_size - 4 < static_cast<size_t>(addr))
    if (static_cast<size_t>(addr) > mem_size - 3)
    {
        std::cout << "invalid memory access to address: " << addr << std::endl;
        exit(1);
        // return ;
    }
    // char buffer[bytes];
    // for (int i = 0; i < bytes; i++)
    //     buffer[i] = 0;
    // for (int i = 0; i < bytes; i++)
    //     buffer[i] = data_memory[addr + i];
    // return buffer[0] | buffer[1] << 8 | buffer[2] << 16 | buffer[3] << 24; // big endian.
    uint32_t word = 0;
    for (int i = 0; i < bytes; i++)
        word |= data_memory[addr + i] << (8 * i);
    return static_cast<int32_t>(word); // extend signed bit by casting to int32_t.
}

DataMemory::DataMemory() : data_memory(mem_size)
{

}