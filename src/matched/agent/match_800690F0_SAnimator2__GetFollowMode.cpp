// 0x800690F0 (8 bytes) — lwz 3, 24(3); blr
// SAnimator2::GetFollowMode(void)

class SAnimator2 {
public:
    void GetFollowMode(void);
};

__attribute__((naked))
void SAnimator2::GetFollowMode(void) {
    asm volatile(
        "lwz 3, 24(3)
"
        "blr
"
    );
}
