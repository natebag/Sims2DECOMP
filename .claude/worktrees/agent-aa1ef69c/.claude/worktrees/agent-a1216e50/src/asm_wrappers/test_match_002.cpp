// Test: Match ESimsApp::SetGameState
// Target: 0x80005410 (8 bytes)
// Expected PPC: stw r4, 0x468(r3); blr
// Expected bytes: 90 83 04 68 4E 80 00 20

typedef int OVERALL_GAME_STATE;

class ESimsApp {
public:
    char _pad[0x468];
    OVERALL_GAME_STATE m_gameState;

    void SetGameState(OVERALL_GAME_STATE state);
};

void ESimsApp::SetGameState(OVERALL_GAME_STATE state) {
    m_gameState = state;
}
