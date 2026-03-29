// 0x800965A8 (64 bytes)
struct ERC;

struct StateMachineState {
    char pad[0x18];
    void** m_vtable;  // 0x18
};

struct StateMachineState_vtable {
    char pad[0x30];
    short m_drawThisOffset;   // 0x30
    char pad2[0x02];
    void* m_drawFn;           // 0x34
};

struct StateMachineStatus {
    StateMachineState* m_curState;  // 0x00

    void DrawCurState(ERC* rc);
};

void StateMachineStatus::DrawCurState(ERC* rc) {
    StateMachineState* state = m_curState;
    if (state != 0) {
        StateMachineState_vtable* vt = (StateMachineState_vtable*)state->m_vtable;
        short offset = vt->m_drawThisOffset;
        void (*fn)(void*, ERC*) = (void (*)(void*, ERC*))vt->m_drawFn;
        void* adjusted = (char*)state + offset;
        fn(adjusted, rc);
    }
}
