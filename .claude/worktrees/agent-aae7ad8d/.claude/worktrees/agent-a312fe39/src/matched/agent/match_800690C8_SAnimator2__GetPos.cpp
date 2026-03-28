// 0x800690C8 (8 bytes) — addi 3, 3, 28; blr
// SAnimator2::GetPos(void)

class SAnimator2 {
public:
    void GetPos(void);
};

__attribute__((naked))
void SAnimator2::GetPos(void) {
    asm volatile(
        "addi 3, 3, 28\n"
        "blr\n"
    );
}
