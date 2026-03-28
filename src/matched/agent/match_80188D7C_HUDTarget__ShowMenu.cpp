class ActionMenu {
public:
    char _data[0xB4];
    void ShowMenu(void);
};

class HUDTarget {
public:
    char _pad[0x740];
    ActionMenu m_actionMenu[4];

    int IsMenuAvailable(int playerIndex) const;
    void ShowMenu(int playerIndex);
};

void HUDTarget::ShowMenu(int playerIndex) {
    IsMenuAvailable(playerIndex);
    m_actionMenu[playerIndex].ShowMenu();
}
