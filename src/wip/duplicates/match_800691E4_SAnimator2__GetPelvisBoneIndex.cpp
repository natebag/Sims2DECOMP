// 0x800691E4 (8 bytes)
class SAnimator2 {
public:
    int GetPelvisBoneIndex();
};

int SAnimator2::GetPelvisBoneIndex() {
    return *(int*)((char*)this + 0x614);
}
