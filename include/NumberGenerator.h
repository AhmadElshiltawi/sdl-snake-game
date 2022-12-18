#ifndef SNAKEGAME_NUMBERGENERATOR_H
#define SNAKEGAME_NUMBERGENERATOR_H

#include <random>
#include "Common.h"

class NumberGenerator {
private:
    std::random_device rd;
    std::uniform_int_distribution<> length_dist;
    std::uniform_int_distribution<> width_dist;

    NumberGenerator() : length_dist(0, BOARD_LENGTH - 1), width_dist(0, BOARD_WIDTH - 1) {};

public:
    NumberGenerator(NumberGenerator const& copy) = delete;
    void operator=(NumberGenerator const& rhs) = delete;

    static NumberGenerator& GetInstance();

    int GenerateRandomLength();
    int GenerateRandomWidth();
};


#endif
