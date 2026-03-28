// 0x8006918C (8 bytes)
class SAnimator2 {
public:
    float GetPauseMultiplier();
};

float SAnimator2::GetPauseMultiplier() {
    return *(float*)((char*)this + 0x104);
}
