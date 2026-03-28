// 0x800690E8 (8 bytes) — lwz 3, 44(3); blr
// SAnimator2::GetAnimState(void)

class SAnimator2 {
public:
    void GetAnimState(void);
};

__attribute__((naked))
void SAnimator2::GetAnimState(void) {
    asm volatile(
        "lwz 3, 44(3)\n"
        "blr\n"
    );
}
