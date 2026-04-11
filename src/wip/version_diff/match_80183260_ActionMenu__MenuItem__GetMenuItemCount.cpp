class ActionMenu {
public:
    class MenuItem {
    public:
        char _pad[0x60];
        MenuItem* m_next;

        const MenuItem* GetNextConst(void) const;
        int GetMenuItemCount(void) const;
    };
};

int ActionMenu::MenuItem::GetMenuItemCount(void) const {
    const MenuItem* p = GetNextConst();
    int count = 1;
    while (p != 0) {
        p = p->GetNextConst();
        count++;
    }
    return count;
}
