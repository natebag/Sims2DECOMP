// 0x800968A0 (100 bytes)
struct ERC;

struct StateMachine {
    char pad[0x18];
    void** m_vtable;  // 0x18
};

struct StateMachine_vtable {
    char pad[0x38];
    short m_drawTopThisOffset;  // 0x38
    char pad2[0x02];
    void* m_drawTopFn;          // 0x3C
};

struct StateMachineManager {
    StateMachine** m_begin;  // 0x00
    StateMachine** m_end;    // 0x04

    void DrawTopmostMachine(ERC* rc);
};

void StateMachineManager::DrawTopmostMachine(ERC* rc) {
    StateMachine** cur = m_begin;
    while (cur != m_end) {
        StateMachine* machine = *cur;
        ++cur;
        StateMachine_vtable* vt = (StateMachine_vtable*)machine->m_vtable;
        short offset = vt->m_drawTopThisOffset;
        void (*fn)(void*, ERC*) = (void (*)(void*, ERC*))vt->m_drawTopFn;
        void* adjusted = (char*)machine + offset;
        fn(adjusted, rc);
    }
}
