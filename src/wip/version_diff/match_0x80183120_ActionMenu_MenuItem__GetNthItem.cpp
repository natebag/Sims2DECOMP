// 0x80183120 ActionMenu::MenuItem::GetNthItem(int) (24B)

struct MenuItem {
    char pad[0x60];
    MenuItem* m_next;
    MenuItem* GetNthItem(int n);
};

MenuItem* MenuItem::GetNthItem(int n) {
    MenuItem* item = this;
    int count = n;
    while (count--) {
        item = item->m_next;
    }
    return item;
}
