/* ESim::DoAnimation(void) at 0x800334B4 (68B) */

extern int gFrameCount;

struct EMat4 {
    float m[16];
};

struct EAnimController {
    void Compute(EMat4&, int);
};

struct ESim {
    char pad_00[0xC0];
    EMat4 m_mat;
    char pad_100[0x334 - 0x100];
    EAnimController m_animCtrl;

    void DoAnimation(void);
    int HasQueuedOperation(void);
};

void ESim::DoAnimation(void) {
    if (HasQueuedOperation() == 0) {
        m_animCtrl.Compute(m_mat, gFrameCount);
    }
}
