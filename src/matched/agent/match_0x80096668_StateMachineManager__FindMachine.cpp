// 0x80096668 (60 bytes)
// ASMPROC_region_gpr_relabel: start_anchor="lwz 9,4(3)" start_mode=at end_anchor="beq" end_mode=at rename="9:0" unsafe_clobber=true
// ASMPROC_insert_mr: after="beq" src=0 dst=9
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
