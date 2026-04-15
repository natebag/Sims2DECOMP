// 0x80183120 ActionMenu::MenuItem::GetNthItem(int) (24B)

namespace ActionMenu {
struct MenuItem {
    char pad[96];
    MenuItem* m_next;
    MenuItem* GetNthItem(int n);
};

MenuItem* MenuItem::GetNthItem(int n) {
    if (n == 0) return this;
    MenuItem* cur = this;
    do {
        cur = cur->m_next;
    } while (--n);
    return cur;
}
}
