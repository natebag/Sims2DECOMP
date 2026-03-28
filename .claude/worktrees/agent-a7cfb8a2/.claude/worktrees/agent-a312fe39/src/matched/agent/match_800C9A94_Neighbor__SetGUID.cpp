// 0x800C9A94 (8 bytes) — stw 4, 8(3); blr
// Neighbor::SetGUID(int)

class Neighbor {
public:
    void SetGUID(int);
};

__attribute__((naked))
void Neighbor::SetGUID(int) {
    asm volatile(
        "stw 4, 8(3)\n"
        "blr\n"
    );
}
