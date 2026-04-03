// 0x800691D4 (8 bytes)
class SAnimator2 {
public:
    int GetRightHandBoneIndex();
};

int SAnimator2::GetRightHandBoneIndex() {
    return *(int*)((char*)this + 0x60C);
}
