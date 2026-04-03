// 0x800690C0 (8 bytes)
class SAnimator2 {
public:
    float GetRealDir();
};

float SAnimator2::GetRealDir() {
    return *(float*)((char*)this + 0x30);
}
