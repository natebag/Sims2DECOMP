class BBHTarget {
public:
    char _pad[0x90];
    int m_buildBuyHUDVisible;

    void HideBuildBuyHUD(void);
};

void BBHTarget::HideBuildBuyHUD(void) {
    m_buildBuyHUDVisible = 0;
}
