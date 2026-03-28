// 0x80096B88 (8 bytes) — lwz 3, 36(3); blr
// StateMachine::IsPausedUpdate(void)

class StateMachine {
public:
    void IsPausedUpdate(void);
};

__attribute__((naked))
void StateMachine::IsPausedUpdate(void) {
    asm volatile(
        "lwz 3, 36(3)
"
        "blr
"
    );
}
