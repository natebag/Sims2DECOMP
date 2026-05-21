// 0x80069470 (112B) SAnimator2::clearSuspendedCarry(void)
// Two-call pattern: ResumeTrack then SetTrackBlendSmooth
// ctrl-first on both calls, this in r31 (callee-save, survives 2 bl calls)

extern const float lbl_803D4C24[3];
extern const float lbl_803D4C28[3];
extern const float gClearSuspend_f2;

class EAnimController {
public:
    void ResumeTrack(int flags);
    void SetTrackBlendSmooth(int flags, float f1, float f2, float f3);
};

struct SAnimator2 {
    void* vtable;
    void* unk4;
    EAnimController* m_inner;  // 0x008
    char pad_12[1552];
    int m_flags;               // 0x61C = 1564
    void clearSuspendedCarry();
};

void SAnimator2::clearSuspendedCarry() {
    int flags = m_flags;
    if (flags & 0x400) {
        EAnimController* ctrl = (EAnimController*)((char*)m_inner + 820);
        m_flags = flags & ~0x400;
        ctrl->ResumeTrack(2048);
        ctrl = (EAnimController*)((char*)m_inner + 820);
        float f2 = gClearSuspend_f2;
        ctrl->SetTrackBlendSmooth(2048, lbl_803D4C24[0], f2, lbl_803D4C28[0]);
    }
}
