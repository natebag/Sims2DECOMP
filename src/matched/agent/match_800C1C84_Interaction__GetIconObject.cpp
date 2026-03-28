// 0x800C1C84 (8 bytes) — lwz 3, 16(3); blr
// Interaction::GetIconObject(void) const

class Interaction {
public:
    void GetIconObject(void) const;
};

__attribute__((naked))
void Interaction::GetIconObject(void) const {
    asm volatile(
        "lwz 3, 16(3)\n"
        "blr\n"
    );
}
