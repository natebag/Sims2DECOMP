// 0x80188CC4 HUDTarget::NotifyMenuRemoveObj(cXObject *) (120B)

class cXObject;

class ActionMenu {
public:
    int IsObjectInMenu(cXObject* obj);
    void CloseMenu();
};

extern char g_hud_some_state[16];

class HUDTarget {
public:
    char _pad0[1856];
    ActionMenu m_primary;
    char _pad1860[2036 - 1857];
    ActionMenu m_secondary;

    void NotifyMenuRemoveObj(cXObject* obj);
};

void HUDTarget::NotifyMenuRemoveObj(cXObject* obj) {
    ActionMenu* m = &m_primary;
    if (m->IsObjectInMenu(obj) != 0) {
        m->CloseMenu();
    }
    if (*(int*)g_hud_some_state != 0) {
        ActionMenu* m2 = &m_secondary;
        if (m2->IsObjectInMenu(obj) != 0) {
            m2->CloseMenu();
        }
    }
}
