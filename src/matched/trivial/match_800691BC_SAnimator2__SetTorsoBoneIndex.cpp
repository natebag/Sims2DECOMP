// 0x800691BC (8 bytes)
class SAnimator2 {
public:
    void SetTorsoBoneIndex(int p);
};

void SAnimator2::SetTorsoBoneIndex(int p) {
    *(int*)((char*)this + 0x618) = p;
}
