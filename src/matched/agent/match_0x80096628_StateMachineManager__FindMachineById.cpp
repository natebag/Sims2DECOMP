// 0x80096628 (64 bytes)
// ASMPROC_region_gpr_relabel: start_anchor="lwz 11,4(3)" start_mode=at end_anchor="beq" end_mode=at rename="11:0" unsafe_clobber=true
// ASMPROC_insert_mr: after="beq" src=0 dst=11
struct StateMachine {
    char pad[0x1C];
    int m_machineId;  // 0x1C

    int GetMachineId(void) const;
};

struct StateMachineManager {
    StateMachine** m_begin;  // 0x00
    StateMachine** m_end;    // 0x04

    StateMachine* FindMachineById(int id);
};

StateMachine* StateMachineManager::FindMachineById(int id) {
    StateMachine** end = m_end;
    StateMachine** cur = m_begin;
    if (cur == end) goto done;
    {
        do {
            StateMachine* m = *cur;
            if (m->m_machineId == id) return m;
            cur++;
        } while (cur != end);
    }
done:
    return 0;
}
