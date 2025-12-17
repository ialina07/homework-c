#pragma once

#include <stdint.h>

typedef union {
    double value;
    uint64_t bits;
} DoubleUnion;

void printDoubleExponential(double num);
