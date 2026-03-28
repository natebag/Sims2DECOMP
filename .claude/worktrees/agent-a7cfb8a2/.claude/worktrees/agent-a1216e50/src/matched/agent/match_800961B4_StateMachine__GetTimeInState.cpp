// 0x800961B4 (8 bytes) — lfs 1, 80(3); blr
// StateMachine::GetTimeInState(void) const

class StateMachine {
public:
    void GetTimeInState(void) const;
};

__attribute__((naked))
void StateMachine::GetTimeInState(void) const {
    asm volatile(
        "lfs 1, 80(3)\n"
        "blr\n"
    );
}
