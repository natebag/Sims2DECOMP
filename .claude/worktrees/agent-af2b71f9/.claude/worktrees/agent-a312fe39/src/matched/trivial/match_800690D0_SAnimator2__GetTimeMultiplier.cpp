// 0x800690D0 (8 bytes)
class SAnimator2 {
public:
    float GetTimeMultiplier();
};

float SAnimator2::GetTimeMultiplier() {
    return *(float*)((char*)this + 0xFC);
}
