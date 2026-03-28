// 0x80090E04 (8 bytes) — lwz 3, 152(3); blr
// LoadingScreenStateMachine::GetLoadingScreen(void)

class LoadingScreenStateMachine {
public:
    void GetLoadingScreen(void);
};

__attribute__((naked))
void LoadingScreenStateMachine::GetLoadingScreen(void) {
    asm volatile(
        "lwz 3, 152(3)
"
        "blr
"
    );
}
