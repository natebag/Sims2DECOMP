// 0x8006A3AC SAnimator2::getIsLeftFootUp(void) (88B)
// Pattern: ctrl.GetTrackPos(0x10000) — float result is range-tested against [const1, const2):
// returns 1 if pos < const1 OR pos >= const2, returns 0 if in-range. cror+bns NaN-aware GE test.

extern const float gFootUp_const1[3];   // non-SDA at 0x803D4CC4
extern const float gFootUp_const2[3];   // non-SDA at 0x803D4CC8

class EAnimController {
public:
    float GetTrackPos(unsigned int flags);
};

class SAnimator2 {
public:
    char pad_0[8];
    void* m_inner;
    int getIsLeftFootUp();
};

int SAnimator2::getIsLeftFootUp() {
    EAnimController* ctrl = (EAnimController*)((char*)m_inner + 820);
    float pos = ctrl->GetTrackPos(0x10000);
    if (pos >= gFootUp_const1[0]) {
        int result = 0;
        if (pos < gFootUp_const2[0]) return result;
    }
    return 1;
}
