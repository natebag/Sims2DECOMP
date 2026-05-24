// 0x802FF7D0 ESubModelShader::CanColorBeModified(void) (64 B)
// FLAGS: -fno-schedule-insns
// Pattern: extra indirection via field_8; same null-checked subobj walk + rlwinm bit-5 as ERShader

struct ERSubObj {
    char pad_0[0x74];
    unsigned int m_colorFlags;    // offset 0x74
    char pad_1[0x3c];
    unsigned int m_modifierMask;  // offset 0xb4
};

struct ERContainer {
    char pad[0x14];
    ERSubObj* m_subObj;  // offset 0x14
};

struct InnerShader {
    char pad_0[0x14];
    ERSubObj* field_14;     // offset 0x14: sub-object pointer (or null)
    ERContainer* field_18;  // offset 0x18: fallback container pointer
};

struct ESubModelShader {
    int field_0;
    int field_4;
    InnerShader* field_8;  // offset 0x8: inner shader pointer
    int CanColorBeModified() const;
};

int ESubModelShader::CanColorBeModified() const {
    InnerShader* inner = (InnerShader*)field_8;
    ERSubObj* obj = (ERSubObj*)inner->field_14;
    ERSubObj* subobj;
    if (obj != 0) {
        subobj = obj;
    } else {
        ERContainer* container = (ERContainer*)inner->field_18;
        subobj = 0;
        if (container != 0) {
            subobj = container->m_subObj;
        }
    }
    unsigned int mask = subobj->m_modifierMask;
    unsigned int flags = subobj->m_colorFlags;
    return ((flags | mask) >> 5) & 1;
}
