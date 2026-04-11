// 0x80096668 (60 bytes)
struct StateMachine;

struct StateMachineManager {
    StateMachine** m_begin;  // 0x00
    StateMachine** m_end;    // 0x04

    StateMachine* FindMachine(StateMachine* machine);
};

StateMachine* StateMachineManager::FindMachine(StateMachine* machine) {
    StateMachine** end = m_end;
    StateMachine** cur = m_begin;
    while (cur != end) {
        StateMachine* m = *cur;
        if (m == machine) {
            return m;
        }
        ++cur;
    }
    return 0;
}
