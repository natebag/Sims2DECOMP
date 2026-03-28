// 0x80069228 (8 bytes) — stw 4, 304(3); blr
// SAnimator2::SetLastCostume(int)

class SAnimator2 {
public:
    void SetLastCostume(int);
};

__attribute__((naked))
void SAnimator2::SetLastCostume(int) {
    asm volatile(
        "stw 4, 304(3)
"
        "blr
"
    );
}
