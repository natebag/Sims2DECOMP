// 0x800342CC (76 bytes)
/* ESim::SetAnim(char *) */
// [VERSION_DIFF] At offset 0x18-0x1c, DOL has li r4,1 then mr r3,r30;
// SN ProDG v3.93 emits mr r3,r30 then li r4,1. All other bytes match.

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
