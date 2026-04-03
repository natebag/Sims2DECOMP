// 0x80069104 (8 bytes)
class SAnimator2 {
public:
    void SetDesiredAnimState(int p);
};

void SAnimator2::SetDesiredAnimState(int p) {
    *(int*)((char*)this + 0xB0) = p;
}
