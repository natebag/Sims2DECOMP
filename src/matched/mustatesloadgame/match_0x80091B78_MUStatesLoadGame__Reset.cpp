struct MUStatesLoadGame {
    char pad[0x1C];
    int m_state;

    void Reset(void);
};

void MUStatesLoadGame::Reset(void) {
    m_state = 0;
}
