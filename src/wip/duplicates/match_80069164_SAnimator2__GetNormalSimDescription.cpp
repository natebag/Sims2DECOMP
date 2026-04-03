// 0x80069164 (8 bytes)
class SAnimator2 {
public:
    int GetNormalSimDescription();
};

int SAnimator2::GetNormalSimDescription() {
    return *(int*)((char*)this + 0x604);
}
