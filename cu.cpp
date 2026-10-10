#include <cstdint>
#include "alu.h"
#include "cpu.h"
#include "main.h"
#include "register.h"


void execute(uint16_t OPcode){
    
    if(OPcode >= 0x8) checkFlagRegister(sourceA, sourceB);
    
    switch(OPcode){
        case 0x0:
            //NO OPERATION
            
            break;
        case 0x1:
            halted = true;
        
            break;
            
        case 0x2:
            //LOAD REGISTER
            registers[sourceA] = sr.TR >> 16;
            registers[sourceB] = sr.TR & 0xFFFF;
            
            break;
        case 0x3:
            //STORE REGISTER
            if(destination == 0){
                sr.TR = ((uint32_t)registers[sourceA] << 16) | registers[sourceB];
            }else if(destination == 1){
                sr.PC = ((uint32_t)registers[sourceA] << 16) | registers[sourceB];
            }
        
            break;
        case 0x4:
            //LOAD IMMEDIATE
            registers[destination] = (int8_t)((sourceA << 4) | sourceB);
            
            break;
        case 0x5:
            //JUMP
            if((destination & sr.FR) != 0) sr.PC += (int8_t)((sourceA << 4) | sourceB);
        
            break;
        case 0x6:
            //MEMORY LOAD
            
            sr.MAR = ((uint32_t)registers[sourceA] << 16) | registers[sourceB];
            sr.MDR = registers[sr.MAR];
            registers[destination] = sr.MDR;
        
            break;
        case 0x7:
            //MEMORY STORE
        
            break;
        case 0x8:
            bitwise_and(destination, sourceA, sourceB);
            break;
        case 0x9:
            bitwise_or(destination, sourceA, sourceB);
            break;
        case 0xA:
            bitwise_xor(destination, sourceA, sourceB);
            break;
        case 0xB:
            bitwise_nor(destination, sourceA, sourceB);
            break;
        case 0xC:
            shift_left(destination, sourceA, sourceB);
            break;
        case 0xD:
            rotate_left(destination, sourceA, sourceB);
            break;
        case 0xE:
            addition(destination, sourceA, sourceB);
            break;
        case 0xF:
            subtraction(destination, sourceA, sourceB);
            break;
            
        
    }
}