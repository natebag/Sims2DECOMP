// 0x800691B4 (8 bytes) — stw 4, 1556(3); blr
// SAnimator2::SetPelvisBoneIndex(int)

class SAnimator2 {
public:
    void SetPelvisBoneIndex(int);
};

__attribute__((naked))
void SAnimator2::SetPelvisBoneIndex(int) {
    asm volatile(
        "stw 4, 1556(3)\n"
        "blr\n"
    );
}
