// 0x80090060 (8 bytes) — stw 4, 12(3); blr
// ELiveMode::SetIntroCameraState(IntroCameraStartState)

class ELiveMode {
public:
    void SetIntroCameraState(IntroCameraStartState);
};

__attribute__((naked))
void ELiveMode::SetIntroCameraState(IntroCameraStartState) {
    asm volatile(
        "stw 4, 12(3)
"
        "blr
"
    );
}
