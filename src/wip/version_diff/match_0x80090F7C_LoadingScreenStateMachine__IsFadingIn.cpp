// FLAGS: -fno-schedule-insns
/* LoadingScreenStateMachine::IsFadingIn(void) at 0x80090F7C (40B) */

struct LSMState_IFI {
    char _pad[0xa0];
    void* field_a0;
    char _pad2[16];
    int field_b4;
};
extern LSMState_IFI* g_lsState_IFI;

struct LoadingScreenStateMachine_IFI {
    int IsFadingIn();
};

int LoadingScreenStateMachine_IFI::IsFadingIn() {
    LSMState_IFI* s = g_lsState_IFI;
    int result = 0;
    if (s->field_b4 & 1) goto return1;
    if (!s->field_a0) return result;
    return1:
    return 1;
}
