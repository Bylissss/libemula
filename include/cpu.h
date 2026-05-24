#pragma once
#include "stdint.h"
#include "stdbool.h"

enum adrr_mode{
    A,
    ABS,
    ABS_X,
    ABS_Y,
    IMMD,
    IMPL,
    IND,
    X_IND,
    IND_Y,
    REL,
    ZPG,
    ZPG_X,
    ZPG_Y
};

enum SR_flags{
    N =       0b10000000,
    V =       0b01000000,
    ingored = 0b00100000,
    B =       0b00010000,
    D =       0b00001000,
    I =       0b00000100,
    Z =       0b00000010,
    C =       0b00000001
};

typedef struct regs{
    uint8_t A;
    uint8_t X;
    uint8_t Y;
    uint8_t SR;
    uint16_t PC;
}regs;

typedef struct instr{
    uint8_t opcode;
    const char* sym;
}instr;

typedef struct cpu{
    instr isa[256];
    regs regs;
}cpu;

void brk();

void res();
void fetch(cpu cpu);
void decode(cpu cpu);
void execute(cpu cpu);