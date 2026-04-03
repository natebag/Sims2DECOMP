// 0x800690F0 (8 bytes)
class SAnimator2 {
public:
    int GetFollowMode();
};

int SAnimator2::GetFollowMode() {
    return *(int*)((char*)this + 0x18);
}
