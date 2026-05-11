// 0x80069470 SAnimator2::clearSuspendedCarry(void) (112B)
// Pattern: m_flags bit-0x400 gate; if set, clear + 2 controller calls (ResumeTrack + SetTrackBlendSmooth).
// Needs r31 callee-save for `this` persistence across the ResumeTrack call. Ctrl re-fetched after the call.

extern const float gClearSuspCarry_f1[3];   // non-SDA at 0x803D4C24
extern const float gClearSuspCarry_f3[3];   // non-SDA at 0x803D4C28
extern const float gClearSuspCarry_f2;      // SDA at r13-32336

class EAnimController {
public:
    void ResumeTrack(int flags);
    void SetTrackBlendSmooth(int flags, float a, float b, float c);
};

class SAnimator2 {
public:
    char pad_0[8];
    void* m_inner;
    char pad_12[1552];
    int m_flags;
    void clearSuspendedCarry();
};

void SAnimator2::clearSuspendedCarry() {
    int flags = m_flags;
    if (flags & 0x400) {
        EAnimController* ctrl = (EAnimController*)((char*)m_inner + 820);
        m_flags = flags & ~0x400;
        ctrl->ResumeTrack(2048);
        EAnimController* ctrl2 = (EAnimController*)((char*)m_inner + 820);
        float f2 = gClearSuspCarry_f2;
        ctrl2->SetTrackBlendSmooth(2048, gClearSuspCarry_f1[0], f2, gClearSuspCarry_f3[0]);
    }
}
