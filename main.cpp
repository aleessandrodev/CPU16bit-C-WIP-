#include <iostream>
#include <vector>
#include <cstdint>
#include <chrono>
#include <thread>
#include "main.h"
#include "register.h"
#include "cpu.h"
#include "cu.h"

RAM ram;

bool halted = false;

int main(){


    while(!halted){

        uint16_t timer = 1;
        std::this_thread::sleep_for(std::chrono::microseconds(timer));

        fetch();
        decode();
        execute(opcode);
        
    }

    std::cout << sr.AR;

    return 0;
    
}