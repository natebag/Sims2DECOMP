// COMPILER: mwcc
// 0x8025A99C C_VECAdd (52B)
//
// Component-wise vector addition ab = a + b. Dolphin SDK vec/vec.c. MWCC GC-1.2.5n.

struct Vec { float x, y, z; };

extern "C" void C_VECAdd(const Vec* a, const Vec* b, Vec* ab) {
    ab->x = a->x + b->x;
    ab->y = a->y + b->y;
    ab->z = a->z + b->z;
}
