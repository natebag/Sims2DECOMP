// 0x800966A4 (60 bytes)
// SN ABI: 16-byte frame (extra 8B outgoing-args reservation), GCC uses 8B.
// ASMPROC_replace_insn: match="stwu 1,-8(1)" replacement="stwu 1,-16(1)"
// ASMPROC_replace_insn: match="stw 0,12(1)" replacement="stw 0,20(1)"
// ASMPROC_replace_insn: match="lwz 0,12(1)" replacement="lwz 0,20(1)"
// ASMPROC_replace_insn: match="la 1,8(1)" replacement="la 1,16(1)"
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
