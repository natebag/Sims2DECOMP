// 0x800691B4 (8 bytes)
class SAnimator2 {
public:
    void SetPelvisBoneIndex(int p);
};

void SAnimator2::SetPelvisBoneIndex(int p) {
    *(int*)((char*)this + 0x614) = p;
}
