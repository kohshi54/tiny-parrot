# tiny-parrot
RV32I simulator in C++.

# Registers
<img width="712" alt="image" src="https://github.com/kohshi54/tiny-parrot/assets/80312261/dd6cc1df-73c1-482f-9310-022209caf916">\
https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf#page=22

# ABI
<img width="710" alt="image" src="https://github.com/kohshi54/tiny-parrot/assets/80312261/a78b5953-c8b2-4861-9d4c-91e4f40d68ca">\
https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf#page=121

# Instruction Format
<img width="708" alt="image" src="https://github.com/kohshi54/tiny-parrot/assets/80312261/96f8c508-8db5-4327-bcca-87fe037a4eba">\
https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf#page=116

# Basic Instruction Set
<img width="712" alt="image" src="https://github.com/kohshi54/tiny-parrot/assets/80312261/d56b3c70-8993-49b8-b1e8-c1ee026d8323">\
https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf#page=116

## I-type Instruction
### ADDI
```
ADDI rd, rs1, imm -> rd = rs1 + imm
```
### ANDI
```
ANDI rd, rs1, imm -> rd = rs1 & imm
```
### ORI
```
ORI rd, rs1, imm -> rd = rs1 | imm
```
### XORI
```
XORI rd, rs1, imm -> rd = rs1 ^ imm
```

## R-type Instruction
### ADD
```
ADD rd, rs1, rs2 -> rd = rs1 + rs2
```
### SUB
```
SUB rd, rs1, rs2 -> rd = rs1 - rs2
```
### AND
```
AND rd, rs1, rs2 -> rd = rs1 & rs2
```
* note that the AND and similar operation in RISC-V is bitwise operation. not logical.
### OR
```
OR rd, rs1, rs2 -> rd = rs1 | rs2
```
### XOR
```
XOR rd, rs1, rs2 -> rd = rs1 ^ rs2
```

