// 0x800C1DAC (8 bytes) — stw 4, 56(3); blr
// Interaction::SetID(int)

class Interaction {
public:
    void SetID(int);
};

__attribute__((naked))
void Interaction::SetID(int) {
    asm volatile(
        "stw 4, 56(3)\n"
        "blr\n"
    );
}
