// 0x80189AB0 HUDTarget::IsPlayerHUDVisible(int) const (24B)
// byte at (this+233)[idx] == 2

struct HUDTarget {
    char pad[233];
    unsigned char m_hudStates[1];
    int IsPlayerHUDVisible(int idx) const;
};

int HUDTarget::IsPlayerHUDVisible(int idx) const {
    return m_hudStates[idx] == 2;
}
