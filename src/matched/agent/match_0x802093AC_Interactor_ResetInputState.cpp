// 0x802093AC (68B) InteractorModule::Interactor::ResetInputState(void)
// Reg-alloc wall: DOL uses r11=&vals[0] (stack ptr) + r10=1 (constant);
// GCC assigns r11=1, r9/r0 for float bits. 12-directive ASMPROC recipe swaps them.
// Also fixes: DOL stores vals[1] (4(r11)) before vals[0] (8(r1)), r0=vals[0] bits, r9=vals[1] bits.
//
// ASMPROC_replace_insn: match="li 11,1" replacement="addi 11,1,8"
// ASMPROC_replace_insn: match="stfs 0,8(1)" replacement="li 10,1"
// ASMPROC_replace_insn: match="lfs 13,8(1)" replacement="stfs 0,4(11)"
// ASMPROC_replace_insn: match="stfs 13,12(1)" replacement="stfs 0,8(1)"
// ASMPROC_replace_insn: match="stw 11,68(3)" replacement="stw 10,68(3)"
// ASMPROC_replace_insn: match="lwz 9,8(1)" replacement="lwz 0,8(1)"
// ASMPROC_replace_insn: match="lwz 0,12(1)" replacement="lwz 9,4(11)"
// ASMPROC_replace_insn: match="stw 9,60(3)" replacement="stw 0,60(3)"
// ASMPROC_replace_insn: match="stw 0,56(3)" replacement="stw 9,56(3)"
// ASMPROC_replace_insn: match="stw 0,64(3)" replacement="stw 9,64(3)"
// ASMPROC_replace_insn: match="stw 9,52(3)" replacement="stw 0,52(3)"
// ASMPROC_replace_insn: match="stw 11,72(3)" replacement="stw 10,72(3)"
// FLAGS: -fno-schedule-insns

struct Interactor {
    char pad[52];
    int m_field52;
    int m_field56;
    int m_field60;
    int m_field64;
    int m_field68;
    int m_field72;
    void ResetInputState();
};

void Interactor::ResetInputState() {
    volatile float vals[2];
    vals[0] = 0.0f;
    vals[1] = vals[0];
    m_field68 = 1;
    int bits0 = *(int*)&vals[0];
    int bits1 = *(int*)&vals[1];
    *(volatile int*)((char*)this + 60) = bits0;
    *(volatile int*)((char*)this + 56) = bits1;
    *(volatile int*)((char*)this + 64) = bits1;
    *(volatile int*)((char*)this + 52) = bits0;
    m_field72 = 1;
}
