// 0x800AD118 (8 bytes) — lwz 3, 4(3); blr
// Behavior::GetOwner(void)

class Behavior {
public:
    void GetOwner(void);
};

__attribute__((naked))
void Behavior::GetOwner(void) {
    asm volatile(
        "lwz 3, 4(3)
"
        "blr
"
    );
}
