// 0x800371FC RemapWallpaperId(unsigned int) (28B)
//
// lis r10, 0x8047; rlwinm r3, r3, 2, 0, 29
// lwz r9, _globals+0xD8(r10); lwz r11, 0(r9); lwzx r10, r11, r3
// lwz r3, 8(r10); blr
//
// _globals at 0x80475DCC, offset 0xD8 = 0x80475EA4 holds a pointer to
// a wallpaper container; container's first field is the wallpaper-entry
// array; the entry's offset-8 field is the remapped id.
//
// GCC emits `lwzx 10,3,11` (RA=r3, RB=r11). DOL has `lwzx 10,11,3`
// (RA=r11, RB=r3). lwzx is commutative on RA+RB but encoded asymmetrically
// — swap_operands fixes the byte encoding without changing semantics.

// ASMPROC_swap_operands: match="lwzx 10,3,11" pos=1,2

struct WPEntry {
    char pad[8];
    unsigned int m_remappedId;
};

struct WPContainer {
    WPEntry **m_arr;
};

struct Globals_RWP {
    char pad[0xD8];
    WPContainer *m_wpContainer;
};

extern "C" Globals_RWP _globals;

unsigned int RemapWallpaperId(unsigned int id) {
    return _globals.m_wpContainer->m_arr[id]->m_remappedId;
}
