#ifndef E_VEC3_H
#define E_VEC3_H

#include "types.h"

// EVec2 - 2D vector (8 bytes: 2 floats)
struct EVec2 {
    float x; // 0x00
    float y; // 0x04

    void Print(void);
};

// EVec3 - 3D vector (12 bytes: 3 floats)
struct EVec3 {
    float x; // 0x00
    float y; // 0x04
    float z; // 0x08

    void Print(void);
    void ToU8s(unsigned char* out) const;
    void FromU8s(unsigned char* in);
    void ToS8s(signed char* out) const;
    void FromS8s(signed char* in);
};

// Global axis constants
extern EVec3 _X_AXIS;
extern EVec3 _Y_AXIS;
extern EVec3 _Z_AXIS;

#endif // E_VEC3_H
