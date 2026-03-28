// 0x800C1D5C (8 bytes) — addi 3, 3, 24; blr
// Interaction::GetStackVars(void)

class Interaction {
public:
    void GetStackVars(void);
};

__attribute__((naked))
void Interaction::GetStackVars(void) {
    asm volatile(
        "addi 3, 3, 24
"
        "blr
"
    );
}
