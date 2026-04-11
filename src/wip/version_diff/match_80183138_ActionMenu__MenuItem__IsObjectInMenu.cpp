class cXObject {};

class ActionMenu {
public:
    class MenuItem {
    public:
        cXObject* m_object;
        char _pad[0x58];
        MenuItem* m_subMenu;
        MenuItem* m_next;

        int IsObjectInMenu(cXObject* obj);
    };
};

int ActionMenu::MenuItem::IsObjectInMenu(cXObject* obj) {
    if (m_object == obj) {
        return 1;
    }
    if (m_next != 0) {
        if (m_next->IsObjectInMenu(obj)) {
            return 1;
        }
    }
    if (m_subMenu != 0) {
        if (m_subMenu->IsObjectInMenu(obj)) {
            return 1;
        }
    }
    return 0;
}
