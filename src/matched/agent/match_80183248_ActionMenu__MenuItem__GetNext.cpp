class ActionMenu {
public:
    class MenuItem {
    public:
        char _pad[0x60];
        MenuItem* m_next;

        MenuItem* GetNext(void);
    };
};

ActionMenu::MenuItem* ActionMenu::MenuItem::GetNext(void) {
    return m_next;
}
