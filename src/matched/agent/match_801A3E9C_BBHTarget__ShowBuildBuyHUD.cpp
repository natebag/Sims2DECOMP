class BBHTarget {
public:
    char _pad[0x90];
    int m_buildBuyHUDVisible;

    void ShowBuildBuyHUD(void);
};

void BBHTarget::ShowBuildBuyHUD(void) {
    m_buildBuyHUDVisible = 1;
}
