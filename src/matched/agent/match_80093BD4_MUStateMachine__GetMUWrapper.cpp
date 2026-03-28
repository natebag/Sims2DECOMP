// 0x80093BD4 (8 bytes) — lwz 3, 152(3); blr
// MUStateMachine::GetMUWrapper(void)

class MUStateMachine {
public:
    void GetMUWrapper(void);
};

__attribute__((naked))
void MUStateMachine::GetMUWrapper(void) {
    asm volatile(
        "lwz 3, 152(3)\n"
        "blr\n"
    );
}
