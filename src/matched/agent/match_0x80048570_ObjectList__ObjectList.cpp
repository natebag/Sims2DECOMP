// ObjectList::ObjectList(void) @ 0x80048570 (32B)
// FLAGS: -fno-schedule-insns
// DOL: stwu; li r0,0; addi r9,r3,8; stw 0(r3); stw 4(r3); stw 4(r9); addi r1; blr
// Inject frame + addi r9 before first store; replace stw 12(r3) with stw 4(r9).
// ASMPROC_nop_before: match="li 0,0"
// ASMPROC_replace_insn: match="nop" replacement="stwu 1,-16(1)"
// ASMPROC_nop_before: match="stw 0,0(3)"
// ASMPROC_replace_insn: match="nop" replacement="addi 9,3,8"
// ASMPROC_replace_insn: match="stw 0,12(3)" replacement="stw 0,4(9)"
// ASMPROC_nop_before: match="blr"
// ASMPROC_replace_insn: match="nop" replacement="addi 1,1,16"

struct OL_c {
    int m_a;    // 0
    int m_b;    // 4
    char _pad8[4];
    int m_c;    // 12
    OL_c();
};

OL_c::OL_c() {
    m_a = 0;
    m_b = 0;
    m_c = 0;
}
