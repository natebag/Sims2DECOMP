class ActionMenu {
public:
    char _pad[9];
    unsigned char m_state;

    void CloseMenu(void);
    void TerminateMenu(void);
};

void ActionMenu::CloseMenu(void) {
    unsigned char state = m_state;
    if (state == 4 || state == 2 || state == 5 || state == 6) {
        m_state = 9;
        TerminateMenu();
    }
}
