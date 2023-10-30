#ifndef Resister_HPP
#define Resister_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Register
{
    public:
        int32_t read(std::string abi);
        void write(std::string abi, int32_t data);
        void dump_registers();

    private:
        const int32_t   x0 = 0;
        int32_t         x1;
        int32_t         x2;
        int32_t         x3;
        int32_t         x4;
        int32_t         x5;
        int32_t         x6;
        int32_t         x7;
        int32_t         x8;
        int32_t         x9;
        int32_t         x10;
        int32_t         x11;
        int32_t         x12;
        int32_t         x13;
        int32_t         x14;
        int32_t         x15;
        int32_t         x16;
        int32_t         x17;
        int32_t         x18;
        int32_t         x19;
        int32_t         x20;
        int32_t         x21;
        int32_t         x22;
        int32_t         x23;
        int32_t         x24;
        int32_t         x25;
        int32_t         x26;
        int32_t         x27;
        int32_t         x28;
        int32_t         x29;
        int32_t         x30;
        int32_t         x31;
};

// struct Registers {
//     int32_t reg[32];

//     Registers() {
//         reg[0] = 0;  // x0 is always 0
//         for (int i = 1; i < 32; ++i) {
//             reg[i] = 0;
//         }
//     }

//     int32_t read(int idx) const {
//         if (idx == 0) return 0;  // x0 is always 0
//         return reg[idx];
//     }

//     void write(int idx, int32_t value) {
//         if (idx != 0) {
//             reg[idx] = value;
//         }
//     }
// };


#endif