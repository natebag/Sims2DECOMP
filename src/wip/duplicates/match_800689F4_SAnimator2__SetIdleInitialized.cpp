// 0x800689F4 (8 bytes)
class SAnimator2 {
public:
    void SetIdleInitialized(int p);
};

void SAnimator2::SetIdleInitialized(int p) {
    *(int*)((char*)this + 0x120) = p;
}
