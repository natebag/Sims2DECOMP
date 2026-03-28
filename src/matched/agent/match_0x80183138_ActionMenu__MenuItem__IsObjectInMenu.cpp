/* ActionMenu::MenuItem::IsObjectInMenu(cXObject *) at 0x80183138 (128b) */

struct cXObject;

struct MenuItem {
    cXObject* m_object;
    char pad_04[0x58];
    MenuItem* m_right;
    MenuItem* m_left;

    int IsObjectInMenu(cXObject* obj);
};

int MenuItem::IsObjectInMenu(cXObject* obj) {
    if (m_object == obj) {
        return 1;
    }
    if (m_left != 0) {
        if (m_left->IsObjectInMenu(obj) != 0) {
            return 1;
        }
    }
    if (m_right != 0) {
        if (m_right->IsObjectInMenu(obj) != 0) {
            return 1;
        }
    }
    return 0;
}
