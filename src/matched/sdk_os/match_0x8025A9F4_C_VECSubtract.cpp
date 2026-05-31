// COMPILER: mwcc
// 0x8025A9F4 C_VECSubtract (52B)
//
// Component-wise vector subtraction ab = a - b. Dolphin SDK vec/vec.c. MWCC GC-1.2.5n.

struct Vec { float x, y, z; };

extern "C" void C_VECSubtract(const Vec* a, const Vec* b, Vec* ab) {
    ab->x = a->x - b->x;
    ab->y = a->y - b->y;
    ab->z = a->z - b->z;
}
