class ActionMenu {
public:
    class MenuItem {
    public:
        char _pad[0x60];
        MenuItem* m_next;

        MenuItem* GetNthItem(int n);
    };
};

ActionMenu::MenuItem* ActionMenu::MenuItem::GetNthItem(int n) {
    MenuItem* item = this;
    for (int i = 0; i < n; i++) {
        item = item->m_next;
    }
    return item;
}
