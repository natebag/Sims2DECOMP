// 0x80069164 (8 bytes) — lwz 3, 1540(3); blr
// SAnimator2::GetNormalSimDescription(void) const

class SAnimator2 {
public:
    void GetNormalSimDescription(void) const;
};

__attribute__((naked))
void SAnimator2::GetNormalSimDescription(void) const {
    asm volatile(
        "lwz 3, 1540(3)\n"
        "blr\n"
    );
}
