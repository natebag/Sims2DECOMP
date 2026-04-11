class ActionMenu {
public:
    char _data[0xB4];
};

class HUDTarget {
public:
    char _pad[0x740];
    ActionMenu m_actionMenu[4];
};

extern HUDTarget* g_hudTarget;

ActionMenu* GetActionMenu(unsigned int index) {
    if (index > 1) {
        return 0;
    }
    if (g_hudTarget == 0) {
        return 0;
    }
    return &g_hudTarget->m_actionMenu[index];
}
