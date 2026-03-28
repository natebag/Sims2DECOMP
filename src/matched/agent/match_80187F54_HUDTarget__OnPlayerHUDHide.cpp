class HUDTarget {
public:
    char _pad_e9[0xE9];
    char m_playerHUDVisible[4];

    void OnPlayerHUDHide(int player);
    void InstallHUDIcons(int player);
};

void HUDTarget::OnPlayerHUDHide(int player) {
    m_playerHUDVisible[player] = 0;
    InstallHUDIcons(player);
}
