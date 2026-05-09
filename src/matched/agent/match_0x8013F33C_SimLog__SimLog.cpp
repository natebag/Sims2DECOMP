// SimLog::SimLog(void) @ 0x8013F33C (60B)
// FLAGS: -fno-schedule-insns
// ASMPROC_nop_before: match="li 0,0"
// ASMPROC_replace_insn: match="nop" replacement="mr 9,3"
// ASMPROC_nop_before: match="mr 9,3"
// ASMPROC_replace_insn: match="nop" replacement="stwu 1,-24(1)"
// ASMPROC_replace_insn: match="stw 0,4(3)" replacement="stw 0,4(9)"
// ASMPROC_nop_before: match="stw 0,8(3)"
// ASMPROC_replace_insn: match="nop" replacement="addi 11,9,12"
// ASMPROC_replace_insn: match="stw 0,8(3)" replacement="stw 0,8(9)"
// ASMPROC_nop_before: match="stw 0,16(3)"
// ASMPROC_replace_insn: match="nop" replacement="addi 8,9,20"
// ASMPROC_replace_insn: match="stw 0,16(3)" replacement="stw 0,4(11)"
// ASMPROC_nop_before: match="stw 0,20(3)"
// ASMPROC_replace_insn: match="nop" replacement="addi 10,9,28"
// ASMPROC_replace_insn: match="stw 0,20(3)" replacement="stw 0,20(9)"
// ASMPROC_replace_insn: match="stw 0,24(3)" replacement="stw 0,4(8)"
// ASMPROC_replace_insn: match="stw 0,32(3)" replacement="stw 0,4(10)"
// ASMPROC_replace_insn: match="stw 0,0(3)" replacement="stw 0,0(9)"
// ASMPROC_nop_before: match="blr"
// ASMPROC_replace_insn: match="nop" replacement="addi 1,1,24"

struct SimLog_c {
    int m_a;    // 0
    int m_b;    // 4
    int m_c;    // 8
    int m_d;    // 12 (NOT zeroed)
    int m_e;    // 16
    int m_f;    // 20
    int m_g;    // 24
    int m_h;    // 28 (NOT zeroed)
    int m_i;    // 32
    SimLog_c();
};

SimLog_c::SimLog_c() {
    m_b = 0;
    m_c = 0;
    m_e = 0;
    m_f = 0;
    m_g = 0;
    m_i = 0;
    m_a = 0;
}
