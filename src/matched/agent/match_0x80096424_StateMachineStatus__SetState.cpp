// 0x80096424 (180 bytes)
struct StateMachineState {
    char pad[0x18];
    void** m_vtable;  // 0x18
};

struct StateMachineState_vtable {
    char pad[0x10];
    short m_startThisOffset;     // 0x10
    char pad2[0x02];
    void* m_startFn;             // 0x14
    short m_shutdownThisOffset;  // 0x18
    char pad3[0x02];
    void* m_shutdownFn;          // 0x1C
    short m_sameThisOffset;      // 0x20
    char pad4[0x02];
    void* m_sameFn;              // 0x24
};

struct StateMachineStatus {
    StateMachineState* m_curState;   // 0x00
    StateMachineState* m_nextState;  // 0x04
    StateMachineState* m_lastState;  // 0x08
    int m_field_0C;                  // 0x0C
    float m_secBeforeNext;           // 0x10
    float m_secInCur;                // 0x14

    void SetState(StateMachineState* state);
};

void StateMachineStatus::SetState(StateMachineState* state) {
    StateMachineState* cur = m_curState;
    if (state == cur) {
        if (state != 0) {
            // Call "same state" callback
            StateMachineState_vtable* vt = (StateMachineState_vtable*)state->m_vtable;
            short offset = vt->m_sameThisOffset;
            void (*fn)(void*) = (void (*)(void*))vt->m_sameFn;
            fn((char*)state + offset);
        }
        return;
    }
    if (cur != 0) {
        // Call shutdown on current state
        StateMachineState_vtable* vt = (StateMachineState_vtable*)cur->m_vtable;
        short offset = vt->m_shutdownThisOffset;
        void (*fn)(void*) = (void (*)(void*))vt->m_shutdownFn;
        fn((char*)cur + offset);
    }
    StateMachineState* old = m_curState;
    m_curState = state;
    m_lastState = old;
    if (state != 0) {
        // Call startup on new state
        StateMachineState_vtable* vt = (StateMachineState_vtable*)state->m_vtable;
        short offset = vt->m_startThisOffset;
        void (*fn)(void*) = (void (*)(void*))vt->m_startFn;
        fn((char*)state + offset);
        m_secInCur = 0.0f;
    }
}
