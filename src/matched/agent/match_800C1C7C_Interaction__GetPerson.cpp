// 0x800C1C7C (8 bytes) — lwz 3, 8(3); blr
// Interaction::GetPerson(void) const

class Interaction {
public:
    void GetPerson(void) const;
};

__attribute__((naked))
void Interaction::GetPerson(void) const {
    asm volatile(
        "lwz 3, 8(3)
"
        "blr
"
    );
}
