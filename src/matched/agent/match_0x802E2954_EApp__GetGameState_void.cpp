// 0x802E2954 EApp::GetGameState(void) (8 B)
struct EApp { char _pad[0x468]; unsigned m_field; unsigned GetGameState(); };
unsigned EApp::GetGameState() { return m_field; }
