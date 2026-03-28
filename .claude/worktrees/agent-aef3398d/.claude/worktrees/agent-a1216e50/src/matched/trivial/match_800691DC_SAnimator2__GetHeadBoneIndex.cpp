// 0x800691DC (8 bytes)
class SAnimator2 {
public:
    int GetHeadBoneIndex();
};

int SAnimator2::GetHeadBoneIndex() {
    return *(int*)((char*)this + 0x610);
}
