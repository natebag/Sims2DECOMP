// 0x80085034 WrapperPaneBase::GetItem (72B)
struct PaneItem {
    int m_type;
    int m_flags;
};

struct WrapperPaneBase {
    char pad[8];
    PaneItem** m_items;
    PaneItem** m_itemsEnd;
    PaneItem* GetItem(int type, int idx);
};

PaneItem* WrapperPaneBase::GetItem(int type, int idx) {
    int count = 0;
    for (PaneItem** it = m_items; it != m_itemsEnd; ++it) {
        PaneItem* item = *it;
        if (item->m_type == type) {
            if (count == idx)
                return item;
            ++count;
        }
    }
    return 0;
}
