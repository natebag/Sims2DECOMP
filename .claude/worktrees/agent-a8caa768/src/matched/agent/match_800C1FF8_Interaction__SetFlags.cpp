// 0x800C1FF8 (8 bytes) — stw 4, 60(3); blr
// Interaction::SetFlags(int)

class Interaction {
public:
    void SetFlags(int);
};

__attribute__((naked))
void Interaction::SetFlags(int) {
    asm volatile(
        "stw 4, 60(3)\n"
        "blr\n"
    );
}
