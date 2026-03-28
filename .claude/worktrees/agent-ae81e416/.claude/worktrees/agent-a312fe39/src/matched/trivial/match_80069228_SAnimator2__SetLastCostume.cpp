// 0x80069228 (8 bytes)
class SAnimator2 {
public:
    void SetLastCostume(int p);
};

void SAnimator2::SetLastCostume(int p) {
    *(int*)((char*)this + 0x130) = p;
}
