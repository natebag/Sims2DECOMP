// 0x80066940 (60B) SAnimator2::stopCurAnim(bool)

extern float SAnimator2_zeroOrConst[3];  // 3-elem forces lis+lfs (not sda21) — 0x803D4AF4

class SAnimator2 {
public:
    void stopCurAnim(bool flag);
};

void SAnimator2::stopCurAnim(bool flag) {
    if (flag) {
        float c = SAnimator2_zeroOrConst[0];
        *(int*)((char*)this + 200) = 0;
        *(float*)((char*)this + 208) = c;
    }
    int v1564 = *(int*)((char*)this + 1564);
    int v220 = *(int*)((char*)this + 220);
    *(int*)((char*)this + 212) = 0;
    *(volatile int*)((char*)this + 224) = v220;
    *(volatile int*)((char*)this + 1564) = v1564 & ~0x100;
}
