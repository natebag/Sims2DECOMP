// 0x80093BCC (8 bytes) — lwz 3, -21360(13); blr
// MUStateMachine::GetHouseNumber(void)

class MUStateMachine {
public:
    void GetHouseNumber(void);
};

__attribute__((naked))
void MUStateMachine::GetHouseNumber(void) {
    asm volatile(
        "lwz 3, -21360(13)\n"
        "blr\n"
    );
}
