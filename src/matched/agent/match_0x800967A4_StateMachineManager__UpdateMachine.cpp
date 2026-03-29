// 0x800967A4 (108 bytes)
struct StateMachine {
    char pad[0x18];
    void** m_vtable;  // 0x18
};

struct StateMachine_vtable {
    char pad[0x28];
    short m_updateThisOffset;   // 0x28
    char pad2[0x02];
    void* m_updateFn;           // 0x2C
};

struct StateMachineManager {
    StateMachine** m_begin;  // 0x00
    StateMachine** m_end;    // 0x04

    void UpdateMachine(float dt);
};

void StateMachineManager::UpdateMachine(float dt) {
    StateMachine** cur = m_begin;
    while (cur != m_end) {
        StateMachine* machine = *cur;
        ++cur;
        StateMachine_vtable* vt = (StateMachine_vtable*)machine->m_vtable;
        short offset = vt->m_updateThisOffset;
        void (*fn)(void*, float) = (void (*)(void*, float))vt->m_updateFn;
        void* adjusted = (char*)machine + offset;
        fn(adjusted, dt);
    }
}
