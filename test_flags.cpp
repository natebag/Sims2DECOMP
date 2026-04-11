// Test file for flag fuzzing
// Based on ESim::SetAnim (0x800342CC, 76 bytes)

struct EAnimController {
    void SetTrackAnim(unsigned int flags, char *animName);
    void SetTrackSpeed(unsigned int flags, float speed);
};

struct ESim_SetAnim {
    char pad_334[0x334];
    EAnimController m_animator;
};

extern float g_floatVal;

void SetAnim(ESim_SetAnim* self, char *animName) {
    self->m_animator.SetTrackAnim(1, animName);
    self->m_animator.SetTrackSpeed(0x10000, g_floatVal);
}
