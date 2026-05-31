// COMPILER: mwcc
// 0x8025AF34 C_VECSquareDistance (60B)
//
// Returns the squared distance between two points. Dolphin SDK vec/vec.c. MWCC GC-1.2.5n.

struct Vec { float x, y, z; };

extern "C" float C_VECSquareDistance(const Vec* a, const Vec* b) {
    float dx = a->x - b->x;
    float dy = a->y - b->y;
    float dz = a->z - b->z;
    return dx * dx + dy * dy + dz * dz;
}
