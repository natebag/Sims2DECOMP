// 0x800C1D64 (8 bytes) — lwz 3, 36(3); blr
// Interaction::GetLocalVars(void)

class Interaction {
public:
    void GetLocalVars(void);
};

__attribute__((naked))
void Interaction::GetLocalVars(void) {
    asm volatile(
        "lwz 3, 36(3)
"
        "blr
"
    );
}
