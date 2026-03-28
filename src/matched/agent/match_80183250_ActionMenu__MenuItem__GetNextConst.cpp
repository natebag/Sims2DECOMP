class ActionMenu {
public:
    class MenuItem {
    public:
        char _pad[0x60];
        MenuItem* m_next;

        const MenuItem* GetNextConst(void) const;
    };
};

const ActionMenu::MenuItem* ActionMenu::MenuItem::GetNextConst(void) const {
    return m_next;
}
