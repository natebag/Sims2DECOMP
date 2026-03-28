// 0x80096B2C (8 bytes) — lwz 3, 32(3); blr
// StateMachine::GetManager(void) const

class StateMachine {
public:
    void GetManager(void) const;
};

__attribute__((naked))
void StateMachine::GetManager(void) const {
    asm volatile(
        "lwz 3, 32(3)\n"
        "blr\n"
    );
}
