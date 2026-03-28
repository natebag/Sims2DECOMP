// 0x80096B80 (8 bytes) — lwz 3, 148(3); blr
// StateMachine::IsEnabled(void)

class StateMachine {
public:
    void IsEnabled(void);
};

__attribute__((naked))
void StateMachine::IsEnabled(void) {
    asm volatile(
        "lwz 3, 148(3)
"
        "blr
"
    );
}
