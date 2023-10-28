#include "register.hpp"

uint32_t Register::read(std::string abi)
{
    if (!abi.compare("zero")) // always return zero
        return x0;
    if (!abi.compare("ra")) // return address
        return x1;
    if (!abi.compare("sp")) // stack pointer
        return x2;
    if (!abi.compare("gp")) // global pointer
        return x3;
    if (!abi.compare("tp")) // thread pointer
        return x4;
    if (!abi.compare("t0")) // tmp
        return x5;
    if (!abi.compare("t1")) // tmp
        return x6;
    if (!abi.compare("t2")) // tmp
        return x7;
    if (!abi.compare("s0") || !abi.compare("fp")) // save or frame pointer
        return x8;
    if (!abi.compare("s1")) // save
        return x9;
    if (!abi.compare("a0")) // argument or return value
        return x10;
    if (!abi.compare("a1")) // argument or return value
        return x11;
    if (!abi.compare("a2")) // argument
        return x12;
    if (!abi.compare("a3")) // argument
        return x13;
    if (!abi.compare("a4")) // argument
        return x14;
    if (!abi.compare("a5")) // argument
        return x15;
    if (!abi.compare("a6")) // argument
        return x16;
    if (!abi.compare("a7")) // argument
        return x17;
    if (!abi.compare("s2")) // save
        return x18;
    if (!abi.compare("s3")) // save
        return x19;
    if (!abi.compare("s4")) // save
        return x20;
    if (!abi.compare("s5")) // save
        return x21;
    if (!abi.compare("s6")) // save
        return x22;
    if (!abi.compare("s7")) // save
        return x23;
    if (!abi.compare("s8")) // save
        return x24;
    if (!abi.compare("s9")) // save
        return x25;
    if (!abi.compare("s10")) // save
        return x26;
    if (!abi.compare("s11")) // save
        return x27;
    if (!abi.compare("t3")) // tmp
        return x28;
    if (!abi.compare("t4")) // tmp
        return x29;
    if (!abi.compare("t5")) // tmp
        return x30;
    if (!abi.compare("t6")) // tmp
        return x31;
    return (0);
}

void Register::write(std::string abi, uint32_t data)
{
    if (!abi.compare("zero")) // do nothing
    if (!abi.compare("ra")) // return address
        x1 = data;
    if (!abi.compare("sp")) // stack pointer
        x2 = data;
    if (!abi.compare("gp")) // global pointer
        x3 = data;
    if (!abi.compare("tp")) // thread pointer
        x4 = data;
    if (!abi.compare("t0")) // tmp
        x5 = data;
    if (!abi.compare("t1")) // tmp
        x6 = data;
    if (!abi.compare("t2")) // tmp
        x7 = data;
    if (!abi.compare("s0") || !abi.compare("fp")) // save or frame pointer
        x8 = data;
    if (!abi.compare("s1")) // save
        x9 = data;
    if (!abi.compare("a0")) // argument or return value
        x10 = data;
    if (!abi.compare("a1")) // argument or return value
        x11 = data;
    if (!abi.compare("a2")) // argument
        x12 = data;
    if (!abi.compare("a3")) // argument
        x13 = data;
    if (!abi.compare("a4")) // argument
        x14 = data;
    if (!abi.compare("a5")) // argument
        x15 = data;
    if (!abi.compare("a6")) // argument
        x16 = data;
    if (!abi.compare("a7")) // argument
        x17 = data;
    if (!abi.compare("s2")) // save
        x18 = data;
    if (!abi.compare("s3")) // save
        x19 = data;
    if (!abi.compare("s4")) // save
        x20 = data;
    if (!abi.compare("s5")) // save
        x21 = data;
    if (!abi.compare("s6")) // save
        x22 = data;
    if (!abi.compare("s7")) // save
        x23 = data;
    if (!abi.compare("s8")) // save
        x24 = data;
    if (!abi.compare("s9")) // save
        x25 = data;
    if (!abi.compare("s10")) // save
        x26 = data;
    if (!abi.compare("s11")) // save
        x27 = data;
    if (!abi.compare("t3")) // tmp
        x28 = data;
    if (!abi.compare("t4")) // tmp
        x29 = data;
    if (!abi.compare("t5")) // tmp
        x30 = data;
    if (!abi.compare("t6")) // tmp
        x31 = data;
}

void Register::dump_registers()
{
    std::string reg_names[] = {
        "ze", "ra", "sp", "gp", "tp",
        "t0", "t1", "t2",
        "s0", "s1",
        "a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7",
        "s2", "s3", "s4", "s5", "s6", "s7", "s8", "s9", "s10", "s11",
        "t3", "t4", "t5", "t6"
    };

    const uint32_t *reg_array[] = {
        &x0, &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8, &x9,
        &x10, &x11, &x12, &x13, &x14, &x15, &x16, &x17, &x18, &x19,
        &x20, &x21, &x22, &x23, &x24, &x25, &x26, &x27, &x28, &x29,
        &x30, &x31
    };

    /*
    for (int i = 0; i < 32; ++i)
    {
        std::cout << std::setw(3) << reg_names[i] << " : ";
        std::cout << *reg_array[i] << std::endl;
    }
    */

    for (const auto& name : reg_names)
        std::cout << std::setw(3) << name << ' ';
    std::cout << std::endl;

    for (const auto& value : reg_array)
        std::cout << std::setw(3) << *value << ' ';
    std::cout << std::endl;
}