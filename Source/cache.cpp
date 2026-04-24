#include "../Header/cache.h"
#include <cstring>
#include <iostream>

Base::cacheSet::cacheSet()
{
    replacement.setWays(CACHE_WAYS);
}

Base::cacheSet::~cacheSet()
{

}

Base::cacheLine* Base::cacheSet::find(uint32_t tag )
{
    for(uint8_t way = 0 ; way < CACHE_WAYS ; way++)
    {
        if(lines[way].valid && lines[way].tag == tag)
        {
            return &lines[way];
        }
    }
    //cache line not found
    return nullptr;
}

Base::cacheLine* Base::cacheSet::replace(uint32_t tag , uint8_t* sourceData)
{
    uint8_t victim = replacement.getVictim();

    lines[victim].valid = true;
    lines[victim].tag = tag;

    std::memcpy(lines[victim].data.data(),sourceData,CACHE_LINE_SIZE);
    return &lines[victim];
}

void Base::cache::initialize(main_memory* memory)
{
    mainMemory = memory;

}

uint32_t Base::cache::read(uint32_t address)
{
    addressParts addressparts(address);
    cacheLine* line = sets[addressparts.setIndex].find(addressparts.tag);

    if(line) //!cache hit
    {
        std::cout<<"Reading from cache address :: 0x"<<address<<" , set:"<<addressparts.setIndex<<" tag:"<<addressparts.tag<<std::endl;
        return *reinterpret_cast<uint32_t*>(&line->data[addressparts.byteOffset]);
    }
    else //! cache miss
    {
        uint32_t lineStart = address & ~(CACHE_LINE_SIZE -1);

        std::array<uint8_t,CACHE_LINE_SIZE> buffer;

        mainMemory->read(lineStart,CACHE_LINE_SIZE,buffer.data());

        cacheLine* newLine = sets[addressparts.setIndex].replace(addressparts.tag,buffer.data());

        return *reinterpret_cast<uint32_t*>(&newLine->data[addressparts.byteOffset]);
    }
}

void Base::cache::write(uint32_t address , uint32_t data)
{
    addressParts addressparts(address);
    cacheLine* line = sets[addressparts.setIndex].find(addressparts.tag);

    if(line) //!cache hit
    {
        std::cout<<"writing to cache address :: 0x"<<address<<" , set: "<<int(addressparts.setIndex)<<" tag:"<<addressparts.tag<<std::endl;
        *reinterpret_cast<uint32_t*>(&line->data[addressparts.byteOffset]) = data;
    }
    else  //!cache miss
    {

    }

    mainMemory->write(address,sizeof(uint32_t),reinterpret_cast<uint8_t*>(&data));
}