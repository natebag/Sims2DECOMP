// 0x8006BFE8 SAnimator2::stopIdleOverlay(void) (88B)
// Pattern: m_flags bit-12 (0x1000) check + conditional bit-13 clear and controller dispatch
// to EAnimController::SetTrackBlendSmooth(eTrackFlags=256, f1, f2, f3).
// Sibling to setFollowEnd (matched at 0x80069920) — same controller-base + 3 float setup
// but with bit-12 gate + SDA-resident middle float.

extern const float gStopIdleOverlay_f1[3];  // non-SDA at 0x803D4DD0
extern const float gStopIdleOverlay_f3[3];  // non-SDA at 0x803D4DD4
extern const float gStopIdleOverlay_f2;     // SDA2 at r13-32340 (0x804FA1AC region)

class EAnimController {
public:
    void SetTrackBlendSmooth(int flags, float a, float b, float c);
};

class SAnimator2 {
public:
    char pad_0[8];
    void* m_inner;     // offset 8
    char pad_12[1552];
    int m_flags;       // offset 1564 (0x61C)
    void stopIdleOverlay();
};

void SAnimator2::stopIdleOverlay() {
    int flags = m_flags;
    if (flags & 0x1000) {
        EAnimController* ctrl = (EAnimController*)((char*)m_inner + 820);
        float f2 = gStopIdleOverlay_f2;
        m_flags = flags & ~0x1000;
        ctrl->SetTrackBlendSmooth(256, gStopIdleOverlay_f1[0], f2, gStopIdleOverlay_f3[0]);
    }
}
