#pragma once 
#include <cstdint>

namespace Base{
    class randomReplacement
    {
        public:
        void setWays(uint8_t numOfWays);
        uint8_t getVictim() const;

        private:
            uint8_t ways = 0;// number of types of caches
    };
}
