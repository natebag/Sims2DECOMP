// 0x800689F4 (8 bytes) — stw 4, 288(3); blr
// SAnimator2::SetIdleInitialized(bool)

class SAnimator2 {
public:
    void SetIdleInitialized(bool);
};

__attribute__((naked))
void SAnimator2::SetIdleInitialized(bool) {
    asm volatile(
        "stw 4, 288(3)\n"
        "blr\n"
    );
}
