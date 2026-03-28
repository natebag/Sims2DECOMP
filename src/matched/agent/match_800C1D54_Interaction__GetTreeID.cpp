// 0x800C1D54 (8 bytes) — lha 3, 44(3); blr
// Interaction::GetTreeID(void) const

class Interaction {
public:
    void GetTreeID(void) const;
};

__attribute__((naked))
void Interaction::GetTreeID(void) const {
    asm volatile(
        "lha 3, 44(3)
"
        "blr
"
    );
}
