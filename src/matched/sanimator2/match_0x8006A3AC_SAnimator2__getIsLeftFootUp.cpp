// 0x8006A3AC (88B) SAnimator2::getIsLeftFootUp(void)
// ASMPROC_inject_before: before="bc 12,0" lines="cror 3,2,1" occurrence=0
// ASMPROC_replace_insn: match="bc 12,0" replacement="bc 4,3" occurrence=0

extern const float lbl_803D4CC4[3];
extern const float lbl_803D4CC8[3];

class EAnimController {
public:
    float GetTrackPos(int flags);
};

struct SAnimator2 {
    void* vtable;
    void* unk4;
    EAnimController* m_inner;  // 0x008
    int getIsLeftFootUp();
};

int SAnimator2::getIsLeftFootUp() {
    EAnimController* ctrl = (EAnimController*)((char*)m_inner + 820);
    float pos = ctrl->GetTrackPos(65536);
    if (pos < lbl_803D4CC4[0])
        return 1;
    if (pos < lbl_803D4CC8[0])
        return 0;
    return 1;
}
