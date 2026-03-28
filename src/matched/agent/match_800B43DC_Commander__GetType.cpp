// 0x800B43DC (8 bytes) — lwz 3, 4(3); blr
// Commander::GetType(void)

class Commander {
public:
    void GetType(void);
};

__attribute__((naked))
void Commander::GetType(void) {
    asm volatile(
        "lwz 3, 4(3)
"
        "blr
"
    );
}
