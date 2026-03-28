struct VTbl_ES {
    int data[8];
};

static VTbl_ES s_vtbl_es;

struct EStream_S {
    int m_field0;
    char pad[0x14];
    VTbl_ES* m_vtbl;
    EStream_S();
};

EStream_S::EStream_S() {
    m_vtbl = &s_vtbl_es;
    m_field0 = 0;
}
