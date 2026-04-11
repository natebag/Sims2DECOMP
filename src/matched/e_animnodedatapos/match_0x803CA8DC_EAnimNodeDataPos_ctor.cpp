// 0x803CA8DC EAnimNodeDataPos::EAnimNodeDataPos (28b)

extern int EAnimNodeDataPos_vtable[];

struct EAnimNodeDataPos {
    int* m_vt;          // 0x00
    char _pad[0x1C];    // 0x04..0x1F
    int m_field_20;     // 0x20 (decimal 32)
    EAnimNodeDataPos();
};

EAnimNodeDataPos::EAnimNodeDataPos() {
    *(int**)this = EAnimNodeDataPos_vtable;
    m_field_20 = 0;
}
