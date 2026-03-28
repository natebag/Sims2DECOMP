// 0x800C1D6C (8 bytes) — lwz 3, 32(3); blr
// Interaction::GetLocalVarsCount(void)

class Interaction {
public:
    void GetLocalVarsCount(void);
};

__attribute__((naked))
void Interaction::GetLocalVarsCount(void) {
    asm volatile(
        "lwz 3, 32(3)
"
        "blr
"
    );
}
