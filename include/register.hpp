#ifndef Resister_HPP
#define Resister_HPP

#include <string>
#include <iostream>

class Register
{
    public:
        uint32_t read(std::string abi);
        void write(std::string abi, uint32_t data);
        void dump_registers();

    private:
        const uint32_t   x0 = 0;
        uint32_t         x1;
        uint32_t         x2;
        uint32_t         x3;
        uint32_t         x4;
        uint32_t         x5;
        uint32_t         x6;
        uint32_t         x7;
        uint32_t         x8;
        uint32_t         x9;
        uint32_t         x10;
        uint32_t         x11;
        uint32_t         x12;
        uint32_t         x13;
        uint32_t         x14;
        uint32_t         x15;
        uint32_t         x16;
        uint32_t         x17;
        uint32_t         x18;
        uint32_t         x19;
        uint32_t         x20;
        uint32_t         x21;
        uint32_t         x22;
        uint32_t         x23;
        uint32_t         x24;
        uint32_t         x25;
        uint32_t         x26;
        uint32_t         x27;
        uint32_t         x28;
        uint32_t         x29;
        uint32_t         x30;
        uint32_t         x31;
};

// struct Registers {
//     uint32_t reg[32];

//     Registers() {
//         reg[0] = 0;  // x0 is always 0
//         for (int i = 1; i < 32; ++i) {
//             reg[i] = 0;
//         }
//     }

//     uint32_t read(int idx) const {
//         if (idx == 0) return 0;  // x0 is always 0
//         return reg[idx];
//     }

//     void write(int idx, uint32_t value) {
//         if (idx != 0) {
//             reg[idx] = value;
//         }
//     }
// };


#endif