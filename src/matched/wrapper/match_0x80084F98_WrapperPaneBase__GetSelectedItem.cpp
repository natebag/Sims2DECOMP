// 0x80084F98 WrapperPaneBase::GetSelectedItem (68B)
struct PaneItem {
    int m_type;
    int m_flags;
};

struct WrapperPaneBase {
    char pad[8];
    PaneItem** m_items;
    PaneItem** m_itemsEnd;
    PaneItem* GetSelectedItem(int type);
};

PaneItem* WrapperPaneBase::GetSelectedItem(int type) {
    for (PaneItem** it = m_items; it != m_itemsEnd; ++it) {
        PaneItem* item = *it;
        if (item->m_type == type && (item->m_flags & 4))
            return item;
    }
    return 0;
}
