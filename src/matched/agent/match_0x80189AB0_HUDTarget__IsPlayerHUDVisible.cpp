// 0x80189AB0 HUDTarget::IsPlayerHUDVisible(int) const (24B)

class HUDTarget {
public:
    char pad[0xE9];
    char m_visibility[8];
    int IsPlayerHUDVisible(int player) const;
};

int HUDTarget::IsPlayerHUDVisible(int player) const {
    return m_visibility[player] == 2;
}
