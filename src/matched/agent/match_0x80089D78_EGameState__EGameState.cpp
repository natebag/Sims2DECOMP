// 0x80089D78 (40B) EGameState::EGameState(void)
// FLAGS: -fno-schedule-insns
// Phantom 16B frame (stwu -16 no LR save). DOL: lis-mr-li reorder + this→r11 alias
// + phantom stw late. 7-directive ASMPROC:
//   Steps 1-2: swap li/lis positions (HA reloc moves to 0x04), convert 2nd lis to mr 11,3.
//   Step 3: phantom stw→li 0,0 (frees slot for late phantom).
//   Steps 4-5: r3→r11 in both stores.
//   Steps 6-7: nop_before frame-restore + replace nop with late phantom stw.
// ASMPROC_replace_insn: match="li 0,0" replacement="lis 9,EGameState_vtable@ha"
// ASMPROC_replace_insn: match="lis 9,EGameState_vtable@ha" replacement="mr 11,3" occurrence=1
// ASMPROC_replace_insn: match="stw 0,8(1)" replacement="li 0,0"
// ASMPROC_replace_insn: match="stw 9,8(3)" replacement="stw 9,8(11)"
// ASMPROC_replace_insn: match="stw 0,0(3)" replacement="stw 0,0(11)"
// ASMPROC_nop_before: match="la 1,16(1)"
// ASMPROC_replace_insn: match="nop" replacement="stw 0,8(1)"

extern int EGameState_vtable[];

struct EGameState {
    int m_0;
    char pad[4];
    int* m_vtable;
    EGameState();
};

EGameState::EGameState() {
    volatile int _dummy;
    _dummy = 0;
    m_vtable = EGameState_vtable;
    m_0 = 0;
}
