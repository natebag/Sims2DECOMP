// 0x800C9A8C (8 bytes) — lwz 3, 8(3); blr
// Neighbor::GetGUID(void)

class Neighbor {
public:
    void GetGUID(void);
};

__attribute__((naked))
void Neighbor::GetGUID(void) {
    asm volatile(
        "lwz 3, 8(3)\n"
        "blr\n"
    );
}
