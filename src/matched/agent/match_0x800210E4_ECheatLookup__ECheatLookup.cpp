// 0x800210E4 ECheatLookup::ECheatLookup(void) (64B)
// Store reorder: DOL puts stw 0,0x5c first, then vtable ptr, then 0x50/0x54/0x58.
// ASMPROC_replace_insn: match="stw 11,72(9)" replacement="stw 0,92(9)"
// ASMPROC_replace_insn: match="stw 0,88(9)" replacement="stw 11,72(9)"
// ASMPROC_replace_insn: match="stw 0,92(9)" replacement="stw 0,80(9)" occurrence=1
// ASMPROC_replace_insn: match="stw 0,80(9)" replacement="stw 0,84(9)" occurrence=1
// ASMPROC_replace_insn: match="stw 0,84(9)" replacement="stw 0,88(9)" occurrence=1

extern int __vt_ECheatLookup_ECL[];

struct ECheatLookup_ECL {
    char pad_00[0x04];
    int m_field04;
    char m_field08;
    char pad_09[0x3F];
    int* m_vtable;
    int m_field4C;
    int m_field50;
    int m_field54;
    int m_field58;
    int m_field5C;

    ECheatLookup_ECL();
};

ECheatLookup_ECL::ECheatLookup_ECL() {
    m_field04 = -1;
    m_field08 = 0;
    m_field4C = 2;
    m_field5C = 0;
    m_vtable = __vt_ECheatLookup_ECL;
    m_field50 = 0;
    m_field54 = 0;
    m_field58 = 0;
}
