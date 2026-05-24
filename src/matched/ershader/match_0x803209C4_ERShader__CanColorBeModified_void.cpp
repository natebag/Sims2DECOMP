// 0x803209C4 ERShader::CanColorBeModified(void) (60 B)
// FLAGS: -fno-schedule-insns
// Pattern: null-checked sub-obj walk; or+rlwinm bit-extract (bit 5 of field_0x74|field_0xb4)

struct ERShader {
    int field_0;
    int field_4;
    int field_8;
    int field_c;
    int field_10;
    void* field_14;   // offset 0x14: sub-object pointer (or null → use container)
    void* field_18;   // offset 0x18: fallback container pointer
    int CanColorBeModified() const;
};

struct ERSubObj {
    char pad_0[0x74];
    unsigned int m_colorFlags;    // offset 0x74
    char pad_1[0x3c];
    unsigned int m_modifierMask;  // offset 0xb4
    char pad_2[0x10];
    void* m_subObjRef;            // offset 0xc4 (unused here)
};

struct ERContainer {
    char pad[0x14];
    ERSubObj* m_subObj;  // offset 0x14
};

int ERShader::CanColorBeModified() const {
    ERSubObj* obj = (ERSubObj*)field_14;
    ERSubObj* r9;
    if (obj != 0) {
        r9 = obj;
    } else {
        ERContainer* container = (ERContainer*)field_18;
        r9 = 0;
        if (container != 0) {
            r9 = container->m_subObj;
        }
    }
    unsigned int mask = r9->m_modifierMask;
    unsigned int flags = r9->m_colorFlags;
    return ((flags | mask) >> 5) & 1;
}
