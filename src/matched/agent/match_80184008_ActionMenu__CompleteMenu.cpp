class ActionMenu {
public:
    char _pad[0xA0];
    unsigned char m_menuDepth;

    void CompleteMenu(void);
};

void ActionMenu::CompleteMenu(void) {
    m_menuDepth--;
}
