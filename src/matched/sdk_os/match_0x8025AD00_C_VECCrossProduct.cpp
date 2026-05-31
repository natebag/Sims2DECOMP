// COMPILER: mwcc
// 0x8025AD00 C_VECCrossProduct (76B) — Dolphin SDK vec/vec.c
//
// Computes axb = a x b through temporaries so the result may alias an input.
// MWCC GC-1.2.5n.

struct Vec { float x, y, z; };

extern "C" void C_VECCrossProduct(const Vec* a, const Vec* b, Vec* axb) {
    float x = a->y * b->z - a->z * b->y;
    float y = a->z * b->x - a->x * b->z;
    float z = a->x * b->y - a->y * b->x;
    axb->x = x;
    axb->y = y;
    axb->z = z;
}
