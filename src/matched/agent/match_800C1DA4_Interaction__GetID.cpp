// 0x800C1DA4 (8 bytes) — lwz 3, 56(3); blr
// Interaction::GetID(void) const

class Interaction {
public:
    void GetID(void) const;
};

__attribute__((naked))
void Interaction::GetID(void) const {
    asm volatile(
        "lwz 3, 56(3)
"
        "blr
"
    );
}
