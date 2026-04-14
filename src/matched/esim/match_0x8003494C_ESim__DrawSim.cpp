// 0x8003494C (92 bytes)
/* ESim::DrawSim(bool) */

struct ESim_DrawSim_Vtable {
    char pad0[4];
    char pad4[0x238 - 4];
    short m_vbaseOff;      /* 0x238 */
    int (*m_func)(void *); /* 0x23C */
};

struct ESim_DrawSim_Inner {
    char pad[4];
    ESim_DrawSim_Vtable *m_vt;  /* offset 4 */
};

struct ESim_DrawSim {
    char pad_3D0[0x3D0];
    ESim_DrawSim_Inner *m_inner; /* 0x3D0 */
    char pad_3D4[0x428 - 0x3D4];
    int m_field_428;             /* 0x428 */

    void DrawSim(bool bArg);
};

void ESim_DrawSim::DrawSim(bool bArg) {
    ESim_DrawSim_Inner *inner = m_inner;
    ESim_DrawSim_Vtable *vt = inner->m_vt;
    short off = vt->m_vbaseOff;
    int (*fn)(void *) = vt->m_func;
    int result = fn((char *)inner + off);
    int val = 0;
    if (result == 0) {
        val = (int)bArg;
    }
    m_field_428 = val;
}
