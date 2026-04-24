#pragma once

#include "memory.h"
#include "replacementAlgorithm.h"
#include<array>

const uint8_t MEMORY_ADDRESS_SIZE = 32 ; // 32-bit address
const uint8_t CACHE_LINE_SIZE = 64;       // 64-byte cache
const uint32_t CACHE_SETS = 64;           // 64 sets  
const uint8_t CACHE_WAYS = 4;             // 4-way set-associativee cache

const uint8_t CACHE_LINE_BYTE_OFFSET_SIZE = 6;
const uint8_t CACHE_LINE_SET_INDEX_SIZE = 6;
const uint8_t CACHE_LINE_TAG_SIZE = 20;


namespace Base
{
    struct cacheLine
    {
        uint32_t tag = 0;
        std::array<uint8_t,CACHE_LINE_SIZE>data;
        bool valid = false;
    };

    struct addressParts
    {
        uint32_t tag;
        uint8_t setIndex = 0;
        uint8_t byteOffset;

        addressParts(uint32_t address)
        {
            byteOffset = address & (CACHE_LINE_SIZE -1);
            setIndex = (address >> CACHE_LINE_BYTE_OFFSET_SIZE) & ((1<<CACHE_LINE_SET_INDEX_SIZE)-1);
            tag = address >> (CACHE_LINE_BYTE_OFFSET_SIZE + CACHE_LINE_SET_INDEX_SIZE) ;
        }
    };

    class cacheSet
    {
        public:
            cacheSet();
            ~cacheSet();

            cacheLine* find(uint32_t tag);
            cacheLine* replace(uint32_t tag,uint8_t* sourceData);

        private:
            std::array<cacheLine,CACHE_WAYS>lines; // array of cache lines
            randomReplacement replacement;

    };

    class cache
    {
        public:
            void initialize(main_memory* memory);
            uint32_t read(uint32_t address);
            void write(uint32_t address , uint32_t data);

        private:
            std::array<cacheSet,CACHE_SETS>sets;
            main_memory* mainMemory;

    };

}








