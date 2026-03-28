// 0x800691E4 (8 bytes) — lwz 3, 1556(3); blr
// SAnimator2::GetPelvisBoneIndex(void)

class SAnimator2 {
public:
    void GetPelvisBoneIndex(void);
};

__attribute__((naked))
void SAnimator2::GetPelvisBoneIndex(void) {
    asm volatile(
        "lwz 3, 1556(3)\n"
        "blr\n"
    );
}
