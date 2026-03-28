// 0x800C1D84 (8 bytes) — stw 4, 40(3); blr
// Interaction::SetPriority(int)

class Interaction {
public:
    void SetPriority(int);
};

__attribute__((naked))
void Interaction::SetPriority(int) {
    asm volatile(
        "stw 4, 40(3)\n"
        "blr\n"
    );
}
