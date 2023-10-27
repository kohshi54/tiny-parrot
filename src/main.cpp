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
        if (!decode(instr))
        {
            std::cout << "execption occurred, abort." << std::endl;
            return (1);
        }
        std::cout << "--------------" << std::endl;
    }
}