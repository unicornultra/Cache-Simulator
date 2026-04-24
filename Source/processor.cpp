#include "../Header/processor.h"

Base::memorySystem::memorySystem()
{
    che.initialize(&mainMemory);
}

Base::memorySystem::~memorySystem()
{

}

uint32_t Base::memorySystem::read(uint32_t address)
{
    return che.read(address);
}

void Base::memorySystem::write(uint32_t address,uint32_t data)
{
    che.write(address,data);
}

void Base::memorySystem::printMainMemory()
{
    mainMemory.print();
}

