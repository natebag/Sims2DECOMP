// 0x800C9794 (8 bytes) — li 3, 8; blr
// Neighbor::GetLatestPersDataVersion(void)

class Neighbor {
public:
    void GetLatestPersDataVersion(void);
};

__attribute__((naked))
void Neighbor::GetLatestPersDataVersion(void) {
    asm volatile(
        "li 3, 8
"
        "blr
"
    );
}
