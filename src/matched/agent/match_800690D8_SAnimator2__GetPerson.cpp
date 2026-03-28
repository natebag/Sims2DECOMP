// 0x800690D8 (8 bytes) — lwz 3, 4(3); blr
// SAnimator2::GetPerson(void)

class SAnimator2 {
public:
    void GetPerson(void);
};

__attribute__((naked))
void SAnimator2::GetPerson(void) {
    asm volatile(
        "lwz 3, 4(3)
"
        "blr
"
    );
}
