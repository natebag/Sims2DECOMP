// 0x800C1D44 (8 bytes) — lwz 3, 4(3); blr
// Interaction::GetType(void)

class Interaction {
public:
    void GetType(void);
};

__attribute__((naked))
void Interaction::GetType(void) {
    asm volatile(
        "lwz 3, 4(3)\n"
        "blr\n"
    );
}
