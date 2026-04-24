#pragma once

#include "memory.h"
#include "cache.h"

namespace Base{
    class memorySystem{
        public:
            memorySystem();
            ~memorySystem();

            uint32_t read(uint32_t address);
            void write(uint32_t address , uint32_t data);
            void printMainMemory();
        
        private:
            main_memory mainMemory;
            cache che;
    };
}

