// 0x80037218 RemapFloorId(unsigned int) (28B)
//
// Sibling of RemapWallpaperId @ 0x800371FC. Identical recipe, different
// _globals offset (0xD4 vs 0xD8) and remap-field offset (0xC vs 0x8).
//
// _globals at 0x80475DCC; offset 0xD4 = 0x80475EA0 holds a pointer to the
// floor container. Container's first field is the floor-entry array;
// each entry's m_remappedId is at offset 0xC.

// ASMPROC_swap_operands: match="lwzx 10,3,11" pos=1,2

struct FloorEntry {
    char pad[12];
    unsigned int m_remappedId;
};

struct FloorContainer {
    FloorEntry **m_arr;
};

struct Globals_RFL {
    char pad[0xD4];
    FloorContainer *m_floorContainer;
};

extern "C" Globals_RFL _globals;

unsigned int RemapFloorId(unsigned int id) {
    return _globals.m_floorContainer->m_arr[id]->m_remappedId;
}
