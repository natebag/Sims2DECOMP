struct MUStatesTransitionSaveExistingGame {
    char pad[0x1C];
    int m_state;

    void Reset(void);
};

void MUStatesTransitionSaveExistingGame::Reset(void) {
    m_state = 0;
}
