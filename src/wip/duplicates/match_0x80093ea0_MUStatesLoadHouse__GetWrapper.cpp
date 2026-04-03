struct MUWrapper;

struct MUStateMachine {
    char pad[0x98];
    MUWrapper *m_wrapper;
};

struct MUStatesLoadHouse {
    char pad[0x08];
    MUStateMachine *m_owner;

    MUWrapper *GetWrapper(void);
};

MUWrapper *MUStatesLoadHouse::GetWrapper(void) {
    return m_owner->m_wrapper;
}
