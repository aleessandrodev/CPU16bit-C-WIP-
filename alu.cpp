#include <cstdint>
#include <iostream>
#include "register.h"

void bitwise_and(uint16_t d, uint16_t sA, uint16_t sB){
    registers[d] = registers[sA] & registers[sB];
    sr.AR = registers[d];
}

void bitwise_or(uint16_t d, uint16_t sA, uint16_t sB){
    registers[d] = registers[sA] | registers[sB];
    sr.AR = registers[d];
}


void bitwise_xor(uint16_t d, uint16_t sA, uint16_t sB){
    registers[d] = registers[sA] ^ registers[sB];
    sr.AR = registers[d];
    
}


void bitwise_nor(uint16_t d, uint16_t sA, uint16_t sB){
    registers[d] = ~(registers[sA] | registers[sB]);
    sr.AR = registers[d];
}


void shift_left(uint16_t d, uint16_t sA, uint16_t sB){
    registers[d] = registers[sA] << registers[sB];
    sr.AR = registers[d];
}


void rotate_left(uint16_t d, uint16_t sA, uint16_t sB){
    registers[d] = registers[sA] << registers[sB];
    sr.AR = registers[d];
}


void addition(uint16_t d, uint16_t sA, uint16_t sB){
    registers[d] = registers[sA] + registers[sB];
    sr.AR = registers[d];
    //std::cout << registers[1] << std::endl;
    
    //std::cout << std::hex << registers[d] << std::endl;
}


void subtraction(uint16_t d, uint16_t sA, uint16_t sB){
    registers[d] = registers[sA] - registers[sB];
    sr.AR = registers[d];
}

void checkFlagRegister(uint16_t sA, uint16_t sB){

    uint16_t a = registers[sA], b = registers[sB];
    
    sr.FR = 0;
    if(a < b) sr.FR |= 0x1;
    if(a == b) sr.FR |= 0x2;
    if(a > b) sr.FR |= 0x4;
    //if(a < b) sr.FR |= 0x8;
}