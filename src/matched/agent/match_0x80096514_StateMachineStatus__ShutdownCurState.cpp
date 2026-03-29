// 0x80096514 (84 bytes)
struct StateMachineState {
    char pad[0x18];
    void** m_vtable;  // 0x18
};

struct StateMachineState_vtable {
    char pad[0x18];
    short m_shutdownThisOffset;   // 0x18
    char pad2[0x02];
    void* m_shutdownFn;           // 0x1C
};

struct StateMachineStatus {
    StateMachineState* m_curState;  // 0x00

    void ShutdownCurState(void);
};

void StateMachineStatus::ShutdownCurState(void) {
    StateMachineState* state = m_curState;
    if (state != 0) {
        StateMachineState_vtable* vt = (StateMachineState_vtable*)state->m_vtable;
        short offset = vt->m_shutdownThisOffset;
        void (*fn)(void*) = (void (*)(void*))vt->m_shutdownFn;
        void* adjusted = (char*)state + offset;
        fn(adjusted);
        m_curState = 0;
    }
}
