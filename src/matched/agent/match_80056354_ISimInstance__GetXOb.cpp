// 0x80056354 (8 bytes) — lwz 3, 808(3); blr
// ISimInstance::GetXOb(void)

class ISimInstance {
public:
    void GetXOb(void);
};

__attribute__((naked))
void ISimInstance::GetXOb(void) {
    asm volatile(
        "lwz 3, 808(3)
"
        "blr
"
    );
}
