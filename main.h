#pragma once
#include <vector>
#include <cstdint>

extern bool halted;

class RAM{
    private:
        std::vector<uint16_t>memory;

    public:
        RAM(size_t size = 65536){
            memory.resize(size, 0x0000);
            memory[0] = 0x4501;
            memory[1] = 0x460A;
            memory[2] = 0xE115;
            memory[3] = 0xF016;
            memory[4] = 0x51FD;
            memory[5] = 0x1000;
            
            
            
            //memory[2] = 0x1000;
        }


        uint16_t read(uint16_t addressMemory){
            if(addressMemory < memory.size()){
                return memory[addressMemory];
            }

            return 1;
        }

        void write(uint16_t addressMemory, uint16_t value){
            if(addressMemory < memory.size()){
                memory[addressMemory] = value;
            }

            
        }

};

extern RAM ram;