// 0x80090E04 LoadingScreenStateMachine::GetLoadingScreen(void) (8 B)
struct LoadingScreenStateMachine { char _pad[0x98]; unsigned m_loadingScreen; unsigned GetLoadingScreen(); };
unsigned LoadingScreenStateMachine::GetLoadingScreen() { return m_loadingScreen; }
