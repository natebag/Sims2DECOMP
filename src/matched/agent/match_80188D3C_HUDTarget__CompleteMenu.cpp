class ActionMenu {
public:
    char _data[0xB4];
    void CompleteMenu(void);
};

class HUDTarget {
public:
    char _pad[0x740];
    ActionMenu m_actionMenu[4];

    int IsMenuAvailable(int playerIndex) const;
    void CompleteMenu(int playerIndex);
};

void HUDTarget::CompleteMenu(int playerIndex) {
    IsMenuAvailable(playerIndex);
    m_actionMenu[playerIndex].CompleteMenu();
}
