// MATCH: 0x80089D78 EGameState::EGameState(void) | Size: 40 bytes
// FLAGS: -O2 -g0

extern int EGameState_vtable[];

struct EGameState {
    int m_field0;
    char pad[4];
    int *m_vtable;
    EGameState();
};

EGameState::EGameState() {
    m_field0 = 0;
    m_vtable = (int *)EGameState_vtable;
}
