/* CLoadingScreen::GetMode(void) const - 0x800578A4 (8B) */

class CLoadingScreen {
public:
    char pad[852];
    int m_mode;

    int GetMode(void) const;
};

int CLoadingScreen::GetMode(void) const {
    return m_mode;
}
