// 0x80096B34 (8 bytes) — lfs 1, 40(3); blr
// StateMachine::GetFrameDeltaTime(void) const

class StateMachine {
public:
    void GetFrameDeltaTime(void) const;
};

__attribute__((naked))
void StateMachine::GetFrameDeltaTime(void) const {
    asm volatile(
        "lfs 1, 40(3)
"
        "blr
"
    );
}
