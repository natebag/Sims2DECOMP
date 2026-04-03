// 0x80005410 (8 bytes) — stw r4, 0x468(r3); blr

class ESimsApp {
public:
    char _pad[0x468];
    int m_gameState;

    void SetGameState(int state);
};

void ESimsApp::SetGameState(int state) {
    m_gameState = state;
}
