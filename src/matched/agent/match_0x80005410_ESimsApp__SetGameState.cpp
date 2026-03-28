/* ESimsApp::SetGameState(OVERALL_GAME_STATE) at 0x80005410 (8B) */

struct ESimsApp {
    char pad[0x468];
    int m_gameState;

    void SetGameState(int state);
};

void ESimsApp::SetGameState(int state) {
    m_gameState = state;
}
