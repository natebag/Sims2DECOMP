class ActionMenu {
public:
    class MenuItem {
    public:
        char _pad_5C[0x5C];
        MenuItem* m_subMenu;
        char _pad_60[4];

        void AddItem(MenuItem* item);
        MenuItem* GetNext(void);
        const MenuItem* GetNextConst(void) const;
        void AddSubItem(MenuItem* item);
    };
};

void ActionMenu::MenuItem::AddSubItem(MenuItem* item) {
    MenuItem* sub = m_subMenu;
    if (sub == 0) {
        m_subMenu = item;
    } else {
        MenuItem* p = sub;
        while (p->GetNextConst() != 0) {
            p = p->GetNext();
        }
        p->AddItem(item);
    }
}
