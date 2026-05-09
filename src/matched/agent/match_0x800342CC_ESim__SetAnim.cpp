// ESim::SetAnim(char*) @ 0x800342CC (76B)
// FLAGS: -fno-schedule-insns
// DOL emits li r4,1 then mr r3,r30; compiled emits mr then li. Swap.
// ASMPROC_swap_adj: a=mr b=li

struct EAnimController {
    void SetTrackAnim(unsigned int flags, char *animName);
    void SetTrackSpeed(unsigned int flags, float speed);
};

struct ESim_SetAnim {
    char pad_334[0x334];
    EAnimController m_animator;

    void SetAnim(char *animName);
};

struct FloatPool {
    char pad[0x11FC];
    float val;
};

extern FloatPool lbl_803D0000;

void ESim_SetAnim::SetAnim(char *animName) {
    m_animator.SetTrackAnim(1, animName);
    m_animator.SetTrackSpeed(0x10000, lbl_803D0000.val);
}
