// 0x80096568 (64 bytes)
struct ERC;

struct StateMachineState {
    char pad[0x18];
    void** m_vtable;  // 0x18
};

struct StateMachineState_vtable {
    char pad[0x28];
    short m_updateThisOffset;   // 0x28
    char pad2[0x02];
    void* m_updateFn;           // 0x2C
};

struct StateMachineStatus {
    StateMachineState* m_curState;  // 0x00

    void UpdateCurState(float dt);
};

void StateMachineStatus::UpdateCurState(float dt) {
    StateMachineState* state = m_curState;
    if (state != 0) {
        StateMachineState_vtable* vt = (StateMachineState_vtable*)state->m_vtable;
        short offset = vt->m_updateThisOffset;
        void (*fn)(void*, float) = (void (*)(void*, float))vt->m_updateFn;
        void* adjusted = (char*)state + offset;
        fn(adjusted, dt);
    }
}
