// 0x80090E04 (8 bytes)
class CLoadingScreen;

class LoadingScreenStateMachine {
public:
    char pad[152];
    CLoadingScreen *m_loadingScreen;

    CLoadingScreen *GetLoadingScreen(void);
};

CLoadingScreen *LoadingScreenStateMachine::GetLoadingScreen(void) {
    return m_loadingScreen;
}
