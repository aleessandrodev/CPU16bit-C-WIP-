#pragma once
#include <cstdint>


extern uint16_t pc;
extern uint16_t opcode;
extern uint16_t destination;
extern uint16_t sourceA;
extern uint16_t sourceB;

void fetch();
void decode();