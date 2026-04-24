#include "../Header/processor.h"
#include<iostream>

int main(){
    Base::memorySystem memory;

    memory.write(0x20 , 0x6139);
    memory.write(0x07 , 0x0108 );
    memory.printMainMemory();

    uint32_t data1 = memory.read(0x20);
    std::cout<<"data1 = 0x"<<data1<<std::endl;

    data1 = memory.read(0x20);
    std::cout<<"data1 = 0x"<<data1<<std::endl;

    for(uint8_t i = 0 ;i<4; i++)
    {
        memory.read(0X0040);
        memory.read(0x1040);        
        memory.read(0x2040);        
        memory.read(0x3040);
    }
}