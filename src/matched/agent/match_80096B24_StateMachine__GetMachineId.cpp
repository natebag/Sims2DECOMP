// 0x80096B24 (8 bytes) — lwz 3, 28(3); blr
// StateMachine::GetMachineId(void) const

class StateMachine {
public:
    void GetMachineId(void) const;
};

__attribute__((naked))
void StateMachine::GetMachineId(void) const {
    asm volatile(
        "lwz 3, 28(3)
"
        "blr
"
    );
}
