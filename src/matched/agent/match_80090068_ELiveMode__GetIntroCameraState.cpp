// 0x80090068 (8 bytes) — lwz 3, 12(3); blr
// ELiveMode::GetIntroCameraState(void)

class ELiveMode {
public:
    void GetIntroCameraState(void);
};

__attribute__((naked))
void ELiveMode::GetIntroCameraState(void) {
    asm volatile(
        "lwz 3, 12(3)\n"
        "blr\n"
    );
}
