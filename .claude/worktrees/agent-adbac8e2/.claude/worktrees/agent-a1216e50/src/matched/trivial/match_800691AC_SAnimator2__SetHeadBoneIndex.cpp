// 0x800691AC (8 bytes)
class SAnimator2 {
public:
    void SetHeadBoneIndex(int p);
};

void SAnimator2::SetHeadBoneIndex(int p) {
    *(int*)((char*)this + 0x610) = p;
}
