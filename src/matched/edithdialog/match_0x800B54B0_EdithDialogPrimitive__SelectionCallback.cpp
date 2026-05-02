// 0x800B54B0 EdithDialogPrimitive::SelectionCallback(int) (36B)

extern short g_edithSelection;

struct EdithDialogPrimitive {
    void* m_vtable;
    char pad[0x84];
    int m_selection;
    void SelectionCallback(int sel);
};

void EdithDialogPrimitive::SelectionCallback(int sel) {
    m_selection = sel;
    if (sel == -1) {
        m_selection = (int)m_vtable - 1;
    }
    g_edithSelection = 1;
}
