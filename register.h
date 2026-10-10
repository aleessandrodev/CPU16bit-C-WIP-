#pragma once
#include <cstdint>

struct special_registers{
    uint16_t PC;
    uint16_t IR;
    uint16_t AR;
    uint32_t TR;
    uint32_t MAR;
    uint32_t MDR;
    uint32_t FR;
};

extern special_registers sr;

extern uint16_t registers[16];