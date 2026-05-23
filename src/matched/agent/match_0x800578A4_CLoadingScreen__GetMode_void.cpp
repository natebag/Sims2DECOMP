// 0x800578A4 CLoadingScreen::GetMode(void) (8 B)
struct CLoadingScreen { char _pad[0x354]; unsigned m_mode; unsigned GetMode(); };
unsigned CLoadingScreen::GetMode() { return m_mode; }
