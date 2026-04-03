struct MUStatesSaveExistingGame {
    char pad[0x1C];
    int m_state;

    void Reset(void);
};

void MUStatesSaveExistingGame::Reset(void) {
    m_state = 0;
}
