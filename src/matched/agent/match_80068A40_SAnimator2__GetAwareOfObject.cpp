// 0x80068A40 (8 bytes) — lwz 3, 1596(3); blr
// SAnimator2::GetAwareOfObject(void)

class SAnimator2 {
public:
    void GetAwareOfObject(void);
};

__attribute__((naked))
void SAnimator2::GetAwareOfObject(void) {
    asm volatile(
        "lwz 3, 1596(3)
"
        "blr
"
    );
}
