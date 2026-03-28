typedef int OVERALL_GAME_STATE;
class EApp {
public:
    char m_pad[1128];
    OVERALL_GAME_STATE m_gameState;
    OVERALL_GAME_STATE GetGameState() const;
};
OVERALL_GAME_STATE EApp::GetGameState() const { return m_gameState; }
