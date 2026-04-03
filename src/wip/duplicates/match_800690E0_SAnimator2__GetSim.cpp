// 0x800690E0 (8 bytes)
class SAnimator2 {
public:
    int GetSim();
};

int SAnimator2::GetSim() {
    return *(int*)((char*)this + 0x8);
}
