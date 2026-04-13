// 0x80189AB0 HUDTarget::IsPlayerHUDVisible (24b)
struct HUDTarget {
    char pad[0xE9];
    char m_visibility[4];
    int IsPlayerHUDVisible(int playerIndex) const;
};

int HUDTarget::IsPlayerHUDVisible(int playerIndex) const {
    return m_visibility[playerIndex] == 2;
}
