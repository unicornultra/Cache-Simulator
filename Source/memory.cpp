#include<cstdint>
#include<cstring>
#include "../Header/memory.h"
#include "array"

#include<iostream>
#include<format>
#include<string>

Base::main_memory::main_memory()
{
    memory = std::make_unique<std::array<uint8_t,MAIN_MEMORY_SIZE>>();

    memory.get()->fill(0x00);
    
}

Base::main_memory::~main_memory()
{

}

void Base::main_memory::read(
    uint32_t startAddress , 
    uint8_t size , 
    uint8_t* destination)
{
    std::cout<<"Reading from main address :: 0x"<<startAddress<<std::endl;
    std::memcpy(destination , &memory.get()->at(startAddress) , size);
}

void Base::main_memory::write(
    uint32_t startAddress , 
    uint8_t size , 
    uint8_t* source)
{
    std::cout<<"writing to main address :: 0x"<<startAddress<<std::endl;
    std::memcpy( &memory.get()->at(startAddress) , source  , size);
}


void Base::main_memory::print()
{
    const int ROWS = 7 ;
    const int COLS = 15 ;
    for(int col=0;col<COLS;col++){
        std::cout<<"_________";
    }std::cout<<std::endl;
    for(int row=0;row<ROWS;row++){
        std::cout<<"|\t";
        for(int col=0;col<COLS;col++){
            
        uint8_t val = memory->at(row * COLS + col);
        std::cout << "0x" 
                  << std::uppercase << std::hex 
                  << static_cast<int>(val) 
                  << "\t";
        }std::cout<<"|"<<std::endl;
    }
    for(int col=0;col<COLS;col++){
        std::cout<<"_________";
    }std::cout<<std::endl;
}