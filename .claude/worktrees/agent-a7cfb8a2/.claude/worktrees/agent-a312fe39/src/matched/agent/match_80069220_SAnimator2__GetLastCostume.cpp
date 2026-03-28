// 0x80069220 (8 bytes) — lwz 3, 304(3); blr
// SAnimator2::GetLastCostume(void)

class SAnimator2 {
public:
    void GetLastCostume(void);
};

__attribute__((naked))
void SAnimator2::GetLastCostume(void) {
    asm volatile(
        "lwz 3, 304(3)\n"
        "blr\n"
    );
}
