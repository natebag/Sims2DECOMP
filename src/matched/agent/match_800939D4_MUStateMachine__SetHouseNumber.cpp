// 0x800939D4 (8 bytes) — stw 3, -21360(13); blr
// MUStateMachine::SetHouseNumber(int)

class MUStateMachine {
public:
    void SetHouseNumber(int);
};

__attribute__((naked))
void MUStateMachine::SetHouseNumber(int) {
    asm volatile(
        "stw 3, -21360(13)
"
        "blr
"
    );
}
