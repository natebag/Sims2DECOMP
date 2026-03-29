// 0x800961F4 (48 bytes)
struct StateMachineState {};

struct StateMachine {
    char pad[0x2C];               // 0x00-0x2B
    StateMachineState** m_begin;  // 0x2C (44)
    StateMachineState** m_end;    // 0x30 (48)

    StateMachineState* FindState(StateMachineState* state);
};

StateMachineState* StateMachine::FindState(StateMachineState* state) {
    StateMachineState** cur = m_begin;
    StateMachineState** end = m_end;
    while (cur != end) {
        StateMachineState* s = *cur;
        if (s == state) {
            return s;
        }
        ++cur;
    }
    return 0;
}
