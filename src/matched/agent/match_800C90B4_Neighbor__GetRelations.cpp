// 0x800C90B4 (8 bytes) — lwz 3, 16(3); blr
// Neighbor::GetRelations(void) const

class Neighbor {
public:
    void GetRelations(void) const;
};

__attribute__((naked))
void Neighbor::GetRelations(void) const {
    asm volatile(
        "lwz 3, 16(3)
"
        "blr
"
    );
}
