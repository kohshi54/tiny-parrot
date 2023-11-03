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

* note that instruction classifiction is based on not only opcode but also with funct7 and fucnt3.

## I-type Instruction
### ADDI
```
ADDI rd, rs1, imm -> rd = rs1 + imm
```
* equivalent to mv instruction when used with addi rd, rs1, 0. RISC-V does not have mv instruction, so that assembler changes mv to addi.
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
### SLLI
```
SLL rd, rs1, rs2 -> rd = rs1 << rs2
```
* note that in order to perform logical operation, the operand value should be cast to (uint 32).
### SRAI
```
SRA rd, rs1, rs2 -> rd = rs1 >> rs2
```
* perform arithmatic shift, which means sign extension is operated during the operatin.
### SRLI
```
SRL rd, rs1, rs2 -> rd = rs1 >> rs2
```
* note that in order to perform logical operation, the operand value should be cast to (uint 32).
### SLTI
```
SLTI rd, rs1, rs2 -> rd = rs1 < imm
```
### SLTIU
```
SLTIU rd, rs1, rs2 -> rd = (uint32_t)rs1 < (uint32_t)imm
```
### JALR
```
JALR rd, rs1, offset -> pc = rs1 + offset; rd = pc + 4
```
* note that JAL is J-type instruction, and JALR is I-type instruction.

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
* note that the AND and similar operation in RISC-V is bitwise operation, not logical.
### OR
```
OR rd, rs1, rs2 -> rd = rs1 | rs2
```
### XOR
```
XOR rd, rs1, rs2 -> rd = rs1 ^ rs2
```
### SLL
```
SLL rd, rs1, rs2 -> rd = rs1 << rs2
```
* note that in order to perform logical operation, the operand value should be cast to (uint 32).
### SRA
```
SRA rd, rs1, rs2 -> rd = rs1 >> rs2
```
### SRL
```
SRL rd, rs1, rs2 -> rd = rs1 >> rs2
```
* note that in order to perform logical operation, the operand value should be cast to (uint 32).
### SLT
```
SLT rd, rs1, rs2 -> rd = rs1 < rs2
```
### SLTU
```
SLTU rd, rs1, rs2 -> rd = (uint32_t)rs1 < (uint32_t)rs2
```

## U-type Instruction
### LUI
```
LUI rd, imm -> rd = (int32_t)imm << 12
```
* note that imm is sign extended before shift left by 12 bits.
### AUIPC
```
AUIPC rd, imm -> rd = pc + ((int32_t)imm << 12)
```
* note that imm is sign extended before shift left by 12 bits.

## B-type Instruction
### BEQ
```
BEQ rs1, rs2, offset -> if (rs1 == rs2) pc += offset
```
* note that offset is 12 bits length, which means the offset range is within ±4 KiB.
### BNE
```
BNE rs1, rs2, offset -> if (rs1 != rs2) pc += offset
```
### BLT
```
BLT rs1, rs2, offset -> if (rs1 < rs2) pc += offset
```
### BGE
```
BGE rs1, rs2, offset -> if (rs1 >= rs2) pc += offset
```
* not that bge include equality (bge stands for branch if greater or equal to).
### BLTU
```
BLTU rs1, rs2, offset -> if ((uint32_t)rs1 < (uint32_t)rs2) pc += offset
```
### BGEU
```
BGEU rs1, rs2, offset -> if ((uint32_t)rs1 >= (uint32_t)rs2) pc += offset
```

## J-type Instruction
### JAL
```
JAL rd, offset -> pc += offset; rd = pc + 4
```
