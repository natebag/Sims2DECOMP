// 0x800939C0 (8 bytes) — lwz 3, -21368(13); blr
// MUStateMachine::GetCurRequest(void)

class MUStateMachine {
public:
    void GetCurRequest(void);
};

__attribute__((naked))
void MUStateMachine::GetCurRequest(void) {
    asm volatile(
        "lwz 3, -21368(13)
"
        "blr
"
    );
}
