#pragma once
#include <cstdint>

void bitwise_and(uint16_t d, uint16_t sA, uint16_t sB);
void bitwise_or(uint16_t d, uint16_t sA, uint16_t sB);
void bitwise_xor(uint16_t d, uint16_t sA, uint16_t sB);
void bitwise_nor(uint16_t d, uint16_t sA, uint16_t sB);
void shift_left(uint16_t d, uint16_t sA, uint16_t sB);
void rotate_left(uint16_t d, uint16_t sA, uint16_t sB);
void addition(uint16_t d, uint16_t sA, uint16_t sB);
void subtraction(uint16_t d, uint16_t sA, uint16_t sB);
void checkFlagRegister(uint16_t sA, uint16_t sB);