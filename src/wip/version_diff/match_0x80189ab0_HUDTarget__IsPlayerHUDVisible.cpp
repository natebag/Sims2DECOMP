// 0x80189ab0 HUDTarget::IsPlayerHUDVisible(int) const (24B)

struct HUDTarget {
    char pad[0xE9];
    char m_hudVisible[1];
    int IsPlayerHUDVisible(int player) const;
};

int HUDTarget::IsPlayerHUDVisible(int player) const {
    return m_hudVisible[player] != 2;
}
