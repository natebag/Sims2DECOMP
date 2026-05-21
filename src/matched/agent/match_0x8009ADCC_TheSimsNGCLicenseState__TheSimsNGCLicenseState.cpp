// 0x8009ADCC (76B) TheSimsNGCLicenseState::TheSimsNGCLicenseState(int)
// ASMPROC_replace_insn: match="stw 8,12(9)" replacement="stw 7,12(9)"
// ASMPROC_replace_insn: match="stw 11,20(9)" replacement="stw 8,12(9)"
// ASMPROC_replace_insn: match="stw 10,24(9)" replacement="stw 11,20(9)"
// ASMPROC_replace_insn: match="stfs 0,76(9)" replacement="stw 10,24(9)"
// ASMPROC_replace_insn: match="stw 8,4(9)" replacement="stfs 0,76(9)"
// ASMPROC_replace_insn: match="stw 7,12(9)" replacement="stw 8,4(9)"

extern int __vt__22TheSimsNGCLicenseState[];

struct TheSimsNGCLicenseState {
    int m_0;
    int m_4;
    int m_8;
    int m_C;
    int m_10;
    int m_14;
    int* m_18;
    int m_1C;
    short m_20;
    char pad[42];
    float m_4C;
    TheSimsNGCLicenseState(int x);
};

TheSimsNGCLicenseState::TheSimsNGCLicenseState(int x) {
    m_0 = x;
    m_C = -1;
    m_14 = 1;
    m_18 = __vt__22TheSimsNGCLicenseState;
    m_4C = 0.0f;
    m_4 = -1;
    m_8 = 0;
    m_10 = 0;
    m_1C = 0;
    m_20 = 0;
}
