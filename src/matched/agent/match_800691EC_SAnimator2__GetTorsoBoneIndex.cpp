// 0x800691EC (8 bytes) — lwz 3, 1560(3); blr
// SAnimator2::GetTorsoBoneIndex(void)

class SAnimator2 {
public:
    void GetTorsoBoneIndex(void);
};

__attribute__((naked))
void SAnimator2::GetTorsoBoneIndex(void) {
    asm volatile(
        "lwz 3, 1560(3)
"
        "blr
"
    );
}
