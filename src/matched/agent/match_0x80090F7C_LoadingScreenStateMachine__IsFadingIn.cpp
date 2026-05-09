// 0x80090F7C (40B) LoadingScreenStateMachine::IsFadingIn(void)
// extern LSMState* generates R_PPC_EMB_SDA21 single-insn SDA2 load.
// GCC puts li 3,0 late (pos 6); DOL wants it at pos 2 (SN scheduler hoisted).
// 5-directive cyclic rotation: shift li 3,0 from pos 6 to pos 2, shift
// lwz/andi./bne right by one, replacing late li with lwz 0,160(9).
// ASMPROC_replace_insn: match="lwz 0,180(9)" replacement="li 3,0"
// ASMPROC_replace_insn: match="andi. 11,0,1" replacement="lwz 0,180(9)"
// ASMPROC_replace_insn: match="bc 4,2,.L4" replacement="andi. 11,0,1"
// ASMPROC_replace_insn: match="lwz 0,160(9)" replacement="bc 4,2,.L4"
// ASMPROC_replace_insn: match="li 3,0" replacement="lwz 0,160(9)" occurrence=1

struct LSMState {
    char _pad[0xa0];
    void* field_a0;
    char _pad2[16];
    int field_b4;
};

extern LSMState* g_loadingScreenState;

struct LoadingScreenStateMachine {
    int IsFadingIn();
};

int LoadingScreenStateMachine::IsFadingIn() {
    LSMState* s = g_loadingScreenState;
    int result = 0;
    if (s->field_b4 & 1) goto return1;
    if (!s->field_a0) return result;
    return1:
    return 1;
}
