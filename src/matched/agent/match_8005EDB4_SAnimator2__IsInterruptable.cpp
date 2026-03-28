// 0x8005EDB4 (8 bytes) — li 3, 1; blr
// SAnimator2::IsInterruptable(void)

class SAnimator2 {
public:
    void IsInterruptable(void);
};

__attribute__((naked))
void SAnimator2::IsInterruptable(void) {
    asm volatile(
        "li 3, 1
"
        "blr
"
    );
}
