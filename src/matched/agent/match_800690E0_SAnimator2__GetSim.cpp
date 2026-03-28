// 0x800690E0 (8 bytes) — lwz 3, 8(3); blr
// SAnimator2::GetSim(void)

class SAnimator2 {
public:
    void GetSim(void);
};

__attribute__((naked))
void SAnimator2::GetSim(void) {
    asm volatile(
        "lwz 3, 8(3)
"
        "blr
"
    );
}
