// 0x800C1D74 (8 bytes) — lwz 3, 20(3); blr
// Interaction::GetTreeTabEntryIndex(void) const

class Interaction {
public:
    void GetTreeTabEntryIndex(void) const;
};

__attribute__((naked))
void Interaction::GetTreeTabEntryIndex(void) const {
    asm volatile(
        "lwz 3, 20(3)
"
        "blr
"
    );
}
