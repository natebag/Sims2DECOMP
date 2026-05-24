// 0x802FF810 ESubModelShader::GetModifiableColor(unsigned int) (52 B)
// FLAGS: -fno-schedule-insns
// Pattern: inner-shader subobj walk (r11=inner, r9=subobj); rlwinm idx*4 + lwzx table lookup at subobj+0x40
// Two-variable form: obj=field_14 for null check, subobj=result (keeps li r9,0 live in else branch)

struct ERSubObj {
    char pad_0[0x40];
    unsigned int m_colors[1];  // color table at offset 0x40
};

struct ERContainer {
    char pad[0x14];
    ERSubObj* m_subObj;  // offset 0x14
};

struct InnerShader {
    char pad_0[0x14];
    ERSubObj* field_14;     // offset 0x14: sub-object pointer
    ERContainer* field_18;  // offset 0x18: fallback container
};

struct ESubModelShader {
    int field_0;
    int field_4;
    InnerShader* field_8;   // offset 0x8
    unsigned int GetModifiableColor(unsigned int index) const;
};

unsigned int ESubModelShader::GetModifiableColor(unsigned int index) const {
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
    return subobj->m_colors[index];
}
