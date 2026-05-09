// 0x800961BC (56B) StateMachine::FindStateById(int)
struct StateMachineState_FSI { int id; };
struct StateMachine_FSI {
    char _pad[44];
    StateMachineState_FSI **m_44;
    StateMachineState_FSI **m_48;
    StateMachineState_FSI* FindStateById(int id);
};
StateMachineState_FSI* StateMachine_FSI::FindStateById(int id) {
    for (StateMachineState_FSI **p = m_44; p != m_48; p++) {
        if ((*p)->id == id) return *p;
    }
    return 0;
}
