// FLAGS: -fno-schedule-insns
// ERC::TriStripRef(int, short*, short*, unsigned char*, signed char*, unsigned char*, bool)
// 0x802F6BAC (52 bytes)

typedef void (*ERC_TriStripShortFn)(void*, int, short*, short*, unsigned char*, signed char*, unsigned char*, bool);

struct ERCVtableShort {
    char pad[48];          // 0x00-0x2F
    short adj_short;       // 0x30 = 48 (lha)
    short _pad2;           // 0x32
    ERC_TriStripShortFn fn_short;  // 0x34 = 52 (lwz)
};

struct ERC2 {
    char m_data[0x70];         // 0x00-0x6F
    ERCVtableShort* m_vtable;  // 0x70 = 112

    void TriStripRefShort(int n, short* pos, short* uv, unsigned char* colors, signed char* norm, unsigned char* extras, bool b);
};

void ERC2::TriStripRefShort(int n, short* pos, short* uv, unsigned char* colors, signed char* norm, unsigned char* extras, bool b) {
    ERCVtableShort* vt = m_vtable;
    short adj = vt->adj_short;
    ERC_TriStripShortFn fn = vt->fn_short;
    fn((char*)this + adj, n, pos, uv, colors, norm, extras, b);
}
