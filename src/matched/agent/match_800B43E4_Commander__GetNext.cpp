// 0x800B43E4 (8 bytes) — lwz 3, 0(3); blr
// Commander::GetNext(void)

class Commander {
public:
    void GetNext(void);
};

__attribute__((naked))
void Commander::GetNext(void) {
    asm volatile(
        "lwz 3, 0(3)
"
        "blr
"
    );
}
