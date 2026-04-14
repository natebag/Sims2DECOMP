// 0x80092ED8 (12 bytes)
class MUStatesTransitionSaveExistingGame {
public:
    char pad[28];
    int m_state;

    void Reset(void);
};

void MUStatesTransitionSaveExistingGame::Reset(void) {
    m_state = 0;
}
