// 0x8009683C (100 bytes)
struct ERC;

struct StateMachine {
    char pad[0x18];
    void** m_vtable;  // 0x18
};

struct StateMachine_vtable {
    char pad[0x30];
    short m_drawThisOffset;   // 0x30
    char pad2[0x02];
    void* m_drawFn;           // 0x34
};

struct StateMachineManager {
    StateMachine** m_begin;  // 0x00
    StateMachine** m_end;    // 0x04

    void DrawMachine(ERC* rc);
};

void StateMachineManager::DrawMachine(ERC* rc) {
    StateMachine** cur = m_begin;
    while (cur != m_end) {
        StateMachine* machine = *cur;
        ++cur;
        StateMachine_vtable* vt = (StateMachine_vtable*)machine->m_vtable;
        short offset = vt->m_drawThisOffset;
        void (*fn)(void*, ERC*) = (void (*)(void*, ERC*))vt->m_drawFn;
        void* adjusted = (char*)machine + offset;
        fn(adjusted, rc);
    }
}
