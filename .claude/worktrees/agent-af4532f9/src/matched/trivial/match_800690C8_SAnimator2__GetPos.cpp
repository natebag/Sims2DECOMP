// 0x800690C8 (8 bytes)
class SAnimator2 {
public:
    int GetPos();
};

int SAnimator2::GetPos() {
    return (int)((char*)this + 0x1C);
}
