// 0x800691EC (8 bytes)
class SAnimator2 {
public:
    int GetTorsoBoneIndex();
};

int SAnimator2::GetTorsoBoneIndex() {
    return *(int*)((char*)this + 0x618);
}
