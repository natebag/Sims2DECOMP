class ActionMenu {
public:
    class MenuItem {
    public:
        char _pad[0x60];
        MenuItem* m_next;

        void AddItem(MenuItem* item);
    };
};

void ActionMenu::MenuItem::AddItem(MenuItem* item) {
    item->m_next = m_next;
    m_next = item;
}
