// 0x800965E8 (64 bytes)
struct ERC;

struct StateMachineState {
    char pad[0x18];
    void** m_vtable;  // 0x18
};

struct StateMachineState_vtable {
    char pad[0x38];
    short m_drawTopThisOffset;  // 0x38
    char pad2[0x02];
    void* m_drawTopFn;          // 0x3C
};

struct StateMachineStatus {
    StateMachineState* m_curState;  // 0x00

    void DrawTopmostCurState(ERC* rc);
};

void StateMachineStatus::DrawTopmostCurState(ERC* rc) {
    StateMachineState* state = m_curState;
    if (state != 0) {
        StateMachineState_vtable* vt = (StateMachineState_vtable*)state->m_vtable;
        short offset = vt->m_drawTopThisOffset;
        void (*fn)(void*, ERC*) = (void (*)(void*, ERC*))vt->m_drawTopFn;
        void* adjusted = (char*)state + offset;
        fn(adjusted, rc);
    }
}
