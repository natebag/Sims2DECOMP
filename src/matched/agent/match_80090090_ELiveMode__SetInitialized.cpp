// 0x80090090 (8 bytes) — stw 4, 48(3); blr
// ELiveMode::SetInitialized(bool)

class ELiveMode {
public:
    void SetInitialized(bool);
};

__attribute__((naked))
void ELiveMode::SetInitialized(bool) {
    asm volatile(
        "stw 4, 48(3)\n"
        "blr\n"
    );
}
