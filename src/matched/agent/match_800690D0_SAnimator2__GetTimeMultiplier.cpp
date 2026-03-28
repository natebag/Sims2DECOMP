// 0x800690D0 (8 bytes) — lfs 1, 252(3); blr
// SAnimator2::GetTimeMultiplier(void)

class SAnimator2 {
public:
    void GetTimeMultiplier(void);
};

__attribute__((naked))
void SAnimator2::GetTimeMultiplier(void) {
    asm volatile(
        "lfs 1, 252(3)\n"
        "blr\n"
    );
}
