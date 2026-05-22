// 0x80187F54 HUDTarget::OnPlayerHUDHide(int) (44B)

class HUDTarget {
public:
    char pad[0xE9];
    char m_visibility[8];
    void InstallHUDIcons(int player);
    void OnPlayerHUDHide(int player);
};

void HUDTarget::OnPlayerHUDHide(int player) {
    m_visibility[player] = 0;
    InstallHUDIcons(player);
}
