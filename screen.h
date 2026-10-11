#pragma once
#include <iostream>
#include <cstdint>
#include "register.h"




class screen{
    private:
        //std::vector<uint16_t>memory;

    public:

        void write(uint16_t value){
            std::cout << value;
        }

        uint16_t read(){
            uint16_t reg;
            std::cin >> reg;
            return reg;
        }

};

extern screen scr;