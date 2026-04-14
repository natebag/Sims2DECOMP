// 0x801f14c0 INVTarget::StartActionMenu(void) (44B)

struct INVTarget;

struct ActionMenu {
    void Start(INVTarget* target, int index);
};

struct INVTarget {
    char pad[0x84];
    int m_tabIndex;
    char pad2[0x319C - 0x84 - 4];
    ActionMenu m_actionMenu;
    void StartActionMenu(void);
};

void INVTarget::StartActionMenu(void) {
    m_actionMenu.Start(this, m_tabIndex);
}
