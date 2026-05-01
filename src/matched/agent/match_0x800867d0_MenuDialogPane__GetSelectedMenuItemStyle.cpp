// 0x800867D0 MenuDialogPane::GetSelectedMenuItemStyle (56B)

struct PaneItem {
    int m_type;
    int m_flags;
    char pad[100];
    int m_style;  // 0x6c = 108
};

struct WrapperPaneBase {
    char pad[8];
    PaneItem** m_items;
    PaneItem** m_itemsEnd;
    PaneItem* GetSelectedItem(int type);
};

struct MenuDialogPane : WrapperPaneBase {
    int GetSelectedMenuItemStyle();
};

int MenuDialogPane::GetSelectedMenuItemStyle() {
    PaneItem* item = GetSelectedItem(1);
    if (item == 0) return 7;
    return item->m_style;
}
