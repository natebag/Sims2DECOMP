// 0x80096B3C (8 bytes) — lwz 3, 144(3); blr
// StateMachine::GetReturnVal(void) const

class StateMachine {
public:
    void GetReturnVal(void) const;
};

__attribute__((naked))
void StateMachine::GetReturnVal(void) const {
    asm volatile(
        "lwz 3, 144(3)\n"
        "blr\n"
    );
}
