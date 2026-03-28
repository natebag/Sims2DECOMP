class ActionMenu {
public:
    class MenuItem {
    public:
        char _pad[0x5C];
        MenuItem* m_subMenu;

        MenuItem* GetSubMenu(void);
    };
};

ActionMenu::MenuItem* ActionMenu::MenuItem::GetSubMenu(void) {
    return m_subMenu;
}
