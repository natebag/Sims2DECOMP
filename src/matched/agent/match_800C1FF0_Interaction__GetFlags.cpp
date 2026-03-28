// 0x800C1FF0 (8 bytes) — lwz 3, 60(3); blr
// Interaction::GetFlags(void) const

class Interaction {
public:
    void GetFlags(void) const;
};

__attribute__((naked))
void Interaction::GetFlags(void) const {
    asm volatile(
        "lwz 3, 60(3)
"
        "blr
"
    );
}
