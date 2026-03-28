class cXObject;

class ActionMenu {
public:
    class MenuItem {
    public:
        int IsObjectInMenu(cXObject* obj);
    };

    char _pad[0x0C];
    MenuItem m_rootItem;

    int IsObjectInMenu(cXObject* obj);
};

int ActionMenu::IsObjectInMenu(cXObject* obj) {
    return m_rootItem.IsObjectInMenu(obj);
}
