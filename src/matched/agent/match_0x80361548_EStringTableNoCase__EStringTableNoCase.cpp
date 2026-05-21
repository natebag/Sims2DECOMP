// 0x80361548 EStringTableNoCase::EStringTableNoCase(void) (40B)
// Non-sequential store order: 8,12,4,0,16,20. DOL uses r0=0, r11=1 preloaded.
// Compiled uses r11=0, r0=1 with lazy load of constant 1.
// 9-directive recipe: swap_adj hoists li r0,1 before first stw,
// then replace_insn renames r11<->r0 throughout.
// ASMPROC_swap_adj: a=stw b=li which=first
// ASMPROC_replace_insn: match="li 11,0" replacement="li 0,0"
// ASMPROC_replace_insn: match="li 0,1" replacement="li 11,1"
// ASMPROC_replace_insn: match="stw 11,8(9)" replacement="stw 0,8(9)"
// ASMPROC_replace_insn: match="stw 0,12(9)" replacement="stw 11,12(9)"
// ASMPROC_replace_insn: match="stw 11,4(9)" replacement="stw 0,4(9)"
// ASMPROC_replace_insn: match="stw 11,0(9)" replacement="stw 0,0(9)"
// ASMPROC_replace_insn: match="stw 11,16(9)" replacement="stw 0,16(9)"
// ASMPROC_replace_insn: match="stw 11,20(9)" replacement="stw 0,20(9)"

struct EStringTableNoCase {
    volatile int m_0;
    volatile int m_4;
    volatile int m_8;
    volatile int m_12;
    volatile int m_16;
    volatile int m_20;
    EStringTableNoCase();
};

EStringTableNoCase::EStringTableNoCase() {
    m_8 = 0;
    m_12 = 1;
    m_4 = 0;
    m_0 = 0;
    m_16 = 0;
    m_20 = 0;
}
