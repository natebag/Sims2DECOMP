struct CLoadingScreen;

struct LoadingScreenStateMachine {
    char pad[0x98];
    CLoadingScreen *m_loadingScreen;

    CLoadingScreen *GetLoadingScreen(void);
};

CLoadingScreen *LoadingScreenStateMachine::GetLoadingScreen(void) {
    return m_loadingScreen;
}
