// 0x8006918C (8 bytes) — lfs 1, 260(3); blr
// SAnimator2::GetPauseMultiplier(void)

class SAnimator2 {
public:
    void GetPauseMultiplier(void);
};

__attribute__((naked))
void SAnimator2::GetPauseMultiplier(void) {
    asm volatile(
        "lfs 1, 260(3)\n"
        "blr\n"
    );
}
