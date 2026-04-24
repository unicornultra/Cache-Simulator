#include "../Header/replacementAlgorithm.h"
#include <random>

void Base::randomReplacement::setWays(uint8_t numOfWays)
{
    ways = numOfWays;
}

uint8_t Base::randomReplacement::getVictim() const
{
    return rand()%ways;
}