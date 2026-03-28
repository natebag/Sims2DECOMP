class ActionMenu {
public:
    char _data[0xB4];
    void CloseMenu(void);
};

class HUDTarget {
public:
    char _pad[0x740];
    ActionMenu m_actionMenu[4];

    void CloseMenu(int playerIndex);
};

void HUDTarget::CloseMenu(int playerIndex) {
    m_actionMenu[playerIndex].CloseMenu();
}
