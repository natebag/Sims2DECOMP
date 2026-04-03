// 0x8006916C (8 bytes)
class SAnimator2 {
public:
    void SetNormalSimDescription(int p);
};

void SAnimator2::SetNormalSimDescription(int p) {
    *(int*)((char*)this + 0x604) = p;
}
