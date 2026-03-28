class HUDTarget {
public:
    char _pad[0xE9];
    unsigned char m_playerHUDVisible[1];

    int IsPlayerHUDVisible(int player) const;
};

int HUDTarget::IsPlayerHUDVisible(int player) const {
    if (m_playerHUDVisible[player] == 2) {
        return 1;
    }
    return 0;
}
