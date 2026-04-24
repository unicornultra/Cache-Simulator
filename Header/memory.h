#pragma once

#include<memory>

const uint32_t MAIN_MEMORY_SIZE = 4 * 1024 * 1024; // 4GB 

namespace Base{

    class main_memory{
        public:
            main_memory();
            ~main_memory();
            void read(uint32_t startAddress , uint8_t size , uint8_t* destination );
            void write(uint32_t startAddress , uint8_t size , uint8_t* source );
            void print();
        private:
        std::unique_ptr<std::array<uint8_t,MAIN_MEMORY_SIZE>>memory;
        
    };
}