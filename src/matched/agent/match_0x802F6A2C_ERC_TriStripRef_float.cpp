// FLAGS: -fno-schedule-insns
// ERC::TriStripRef(int, float*, float*, unsigned char*, signed char*, unsigned char*, bool)
// 0x802F6A2C (52 bytes)

typedef void (*ERC_TriStripFloatFn)(void*, int, float*, float*, unsigned char*, signed char*, unsigned char*, bool);

struct ERCVtable {
    char pad[32];          // 0x00-0x1F
    short adj_float;       // 0x20 = 32 (lha)
    short _pad2;           // 0x22
    ERC_TriStripFloatFn fn_float;  // 0x24 = 36 (lwz)
};

struct ERC {
    char m_data[0x70];     // 0x00-0x6F
    ERCVtable* m_vtable;   // 0x70 = 112

    void TriStripRef(int n, float* pos, float* uv, unsigned char* colors, signed char* norm, unsigned char* extras, bool b);
};

void ERC::TriStripRef(int n, float* pos, float* uv, unsigned char* colors, signed char* norm, unsigned char* extras, bool b) {
    ERCVtable* vt = m_vtable;
    short adj = vt->adj_float;
    ERC_TriStripFloatFn fn = vt->fn_float;
    fn((char*)this + adj, n, pos, uv, colors, norm, extras, b);
}
