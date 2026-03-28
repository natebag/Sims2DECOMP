// 0x80090098 (8 bytes) — lwz 3, 48(3); blr
// ELiveMode::IsInitialized(void)

class ELiveMode {
public:
    void IsInitialized(void);
};

__attribute__((naked))
void ELiveMode::IsInitialized(void) {
    asm volatile(
        "lwz 3, 48(3)
"
        "blr
"
    );
}
