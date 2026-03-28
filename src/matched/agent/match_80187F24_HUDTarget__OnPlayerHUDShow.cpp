class HUDTarget {
public:
    char _pad_e9[0xE9];
    char m_playerHUDVisible[4];

    void OnPlayerHUDShow(int player);
    void UpdateActivePlayer(int player, bool active);
};

void HUDTarget::OnPlayerHUDShow(int player) {
    m_playerHUDVisible[player] = 2;
    UpdateActivePlayer(player, true);
}
