struct MUWrapper;

struct MUStateMachine {
    char pad[0x98];
    MUWrapper *m_wrapper;

    MUWrapper *GetMUWrapper(void);
};

MUWrapper *MUStateMachine::GetMUWrapper(void) {
    return m_wrapper;
}
