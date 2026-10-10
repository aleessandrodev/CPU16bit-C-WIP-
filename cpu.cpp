#include <iostream>
#include <vector>
#include <cstdint>
#include "main.h"
#include "register.h"


uint16_t opcode = 0;
uint16_t destination = 0;
uint16_t sourceA = 0;
uint16_t sourceB = 0;

void fetch(){

    sr.IR = ram.read(sr.PC);
    sr.PC++;
    sr.TR++;
    //return 0;
}

void decode(){


    opcode = (sr.IR >> 12) & 0xF;
    destination = (sr.IR >> 8) & 0xF;
    sourceA = (sr.IR >> 4) & 0xF;
    sourceB = (sr.IR >> 0) & 0xF;
    //std::cout << std::hex << (int)opcode << (int)destination << (int)sourceA << (int)sourceB << std::endl;
    
    //return 0;
}