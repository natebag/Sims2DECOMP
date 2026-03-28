struct VTbl_BG {
    int data[4];
};

static VTbl_BG s_vtbl_bg;

struct Background_S {
    VTbl_BG* m_vtbl;
    Background_S();
};

Background_S::Background_S() {
    m_vtbl = &s_vtbl_bg;
}
