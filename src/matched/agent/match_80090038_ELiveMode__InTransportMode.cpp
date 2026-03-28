// 0x80090038 (8 bytes) — lwz 3, 40(3); blr
// ELiveMode::InTransportMode(void)

class ELiveMode {
public:
    void InTransportMode(void);
};

__attribute__((naked))
void ELiveMode::InTransportMode(void) {
    asm volatile(
        "lwz 3, 40(3)
"
        "blr
"
    );
}
