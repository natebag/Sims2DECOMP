// 0x80089E10 EGameState::GetState(void) (16B)

struct EGameStateId {
    int value;
    EGameStateId() {}
    EGameStateId(const EGameStateId& o) : value(o.value) {}
};

struct EGameState {
    EGameStateId m_stateId;
    char _pad[4];
    int *m_vtable;
    EGameStateId GetState(void);
};

EGameStateId EGameState::GetState(void) {
    return m_stateId;
}
