// 0x800690E8 (8 bytes)
class SAnimator2 {
public:
    int GetAnimState();
};

int SAnimator2::GetAnimState() {
    return *(int*)((char*)this + 0x2C);
}
