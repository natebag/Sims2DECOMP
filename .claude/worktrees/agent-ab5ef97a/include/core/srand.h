#ifndef SRAND_H
#define SRAND_H

#include "types.h"

// Random number functions - from srand.obj
// Uses SDA global for seed storage

// Get current random seed (SDA global at r13-0x6008)
unsigned int GetSRandSeed(void);

// Set random seed (SDA global at r13-0x6008)
void SetSRandSeed(unsigned int seed);

// Returns random int in range [0, range)
// Uses rand() then modulo
unsigned int RangedRandInt(unsigned int range);

// External: standard rand() function
extern "C" int rand(void);

#endif // SRAND_H
