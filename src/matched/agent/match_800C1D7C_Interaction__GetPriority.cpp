// 0x800C1D7C (8 bytes) — lwz 3, 40(3); blr
// Interaction::GetPriority(void) const

class Interaction {
public:
    void GetPriority(void) const;
};

__attribute__((naked))
void Interaction::GetPriority(void) const {
    asm volatile(
        "lwz 3, 40(3)
"
        "blr
"
    );
}
