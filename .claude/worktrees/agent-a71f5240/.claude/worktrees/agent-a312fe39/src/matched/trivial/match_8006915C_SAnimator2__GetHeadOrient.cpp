// 0x8006915C (8 bytes)
class SAnimator2 {
public:
    int GetHeadOrient();
};

int SAnimator2::GetHeadOrient() {
    return (int)((char*)this + 0x180);
}
