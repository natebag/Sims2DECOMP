// 0x800966A4 (60 bytes)
struct StateMachine;

struct SMList {
    StateMachine** m_begin;  // 0x00
    StateMachine** m_end;    // 0x04
};

struct StateMachineManager {
    SMList m_list;    // 0x00
    SMList m_list2;   // 0x08

    static void Startup(void);
};

extern StateMachineManager* g_stateMachineManager;

StateMachineManager* __builtin_new_sm(unsigned int);

void StateMachineManager::Startup(void) {
    StateMachineManager* mgr = (StateMachineManager*)__builtin_new_sm(16);
    mgr->m_list.m_begin = 0;
    mgr->m_list.m_end = 0;
    SMList* list2 = &mgr->m_list2;
    list2->m_end = 0;
    g_stateMachineManager = mgr;
}
