// 0x80005410 ESimsApp::SetGameState(OVERALL_GAME_STATE) (8 B)
typedef int OVERALL_GAME_STATE;
struct ESimsApp { char _pad[0x468]; int m_gameState; void SetGameState(OVERALL_GAME_STATE); };
void ESimsApp::SetGameState(OVERALL_GAME_STATE state) { m_gameState = state; }
