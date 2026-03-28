// 0x80090F74 (8 bytes) — lwz 3, -32160(13); blr
// LoadingScreenStateMachine::GetSingleton(void)

class LoadingScreenStateMachine {
public:
    void GetSingleton(void);
};

__attribute__((naked))
void LoadingScreenStateMachine::GetSingleton(void) {
    asm volatile(
        "lwz 3, -32160(13)\n"
        "blr\n"
    );
}
