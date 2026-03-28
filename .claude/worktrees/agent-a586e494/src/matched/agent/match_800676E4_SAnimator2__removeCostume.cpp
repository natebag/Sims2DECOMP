// 0x800676E4 (8 bytes) — li 3, 1; blr
// SAnimator2::removeCostume(void)

class SAnimator2 {
public:
    void removeCostume(void);
};

__attribute__((naked))
void SAnimator2::removeCostume(void) {
    asm volatile(
        "li 3, 1\n"
        "blr\n"
    );
}
