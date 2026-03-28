typedef int OVERALL_GAME_STATE;
class EApp {
public:
    char m_pad[1128];
    OVERALL_GAME_STATE m_gameState;
    void SetGameState(OVERALL_GAME_STATE);
};
void EApp::SetGameState(OVERALL_GAME_STATE state) { m_gameState = state; }
