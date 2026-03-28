// 0x8006915C (8 bytes) — addi 3, 3, 384; blr
// SAnimator2::GetHeadOrient(void)

class SAnimator2 {
public:
    void GetHeadOrient(void);
};

__attribute__((naked))
void SAnimator2::GetHeadOrient(void) {
    asm volatile(
        "addi 3, 3, 384
"
        "blr
"
    );
}
