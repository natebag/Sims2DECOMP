// 0x800691A4 (8 bytes)
class SAnimator2 {
public:
    void SetRightHandBoneIndex(int p);
};

void SAnimator2::SetRightHandBoneIndex(int p) {
    *(int*)((char*)this + 0x60C) = p;
}
