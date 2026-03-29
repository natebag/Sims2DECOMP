// 0x80095DC4 (56 bytes)
struct StateMachineState;

struct StateMachine {
    char pad[0x84];                  // 0x00-0x83
    StateMachineState* m_pendingState;  // 0x84 (132)

    StateMachineState* FindStateById(int id);
    void CallState(int id);
};

void StateMachine::CallState(int id) {
    StateMachineState* state = FindStateById(id);
    if (state != 0) {
        m_pendingState = state;
    }
}
