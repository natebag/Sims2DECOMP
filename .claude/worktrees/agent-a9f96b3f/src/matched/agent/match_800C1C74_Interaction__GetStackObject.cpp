// 0x800C1C74 (8 bytes) — lwz 3, 12(3); blr
// Interaction::GetStackObject(void) const

class Interaction {
public:
    void GetStackObject(void) const;
};

__attribute__((naked))
void Interaction::GetStackObject(void) const {
    asm volatile(
        "lwz 3, 12(3)\n"
        "blr\n"
    );
}
