// 0x8039CFFC StateMachineState::SetFlag(unsigned int) (20 B)

struct StateMachineState {
    char pad[0x10];
    unsigned int m_flags;
    unsigned int SetFlag(unsigned int flag);
};

unsigned int StateMachineState::SetFlag(unsigned int flag) {
    unsigned int old = m_flags;
    m_flags = old | flag;
    return old;
}
