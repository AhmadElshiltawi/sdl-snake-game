

#include "../include/NumberGenerator.h"

NumberGenerator &NumberGenerator::GetInstance() {
    static NumberGenerator instance_;
    return instance_;
}

int NumberGenerator::GenerateRandomLength() {
    return length_dist(rd);
}

int NumberGenerator::GenerateRandomWidth() {
    return width_dist(rd);
}
