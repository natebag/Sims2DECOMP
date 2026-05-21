// 0x8006BFE8 (88B) SAnimator2::stopIdleOverlay(void)
// ctrl-first source ordering: EAnimController* ctrl computed before float const setup

extern const float lbl_803D4DD0[3];
extern const float lbl_803D4DD4[3];
extern const float gStopIdleOverlay_f2;

class EAnimController {
public:
    void SetTrackBlendSmooth(int flags, float f1, float f2, float f3);
};

struct SAnimator2 {
    void* vtable;
    void* unk4;
    EAnimController* m_inner;  // 0x008
    char pad_12[1552];
    int m_flags;               // 0x61C = 1564
    void stopIdleOverlay();
};

void SAnimator2::stopIdleOverlay() {
    int flags = m_flags;
    if (flags & 0x1000) {
        EAnimController* ctrl = (EAnimController*)((char*)m_inner + 820);
        float f2 = gStopIdleOverlay_f2;
        m_flags = flags & ~0x1000;
        ctrl->SetTrackBlendSmooth(256, lbl_803D4DD0[0], f2, lbl_803D4DD4[0]);
    }
}
