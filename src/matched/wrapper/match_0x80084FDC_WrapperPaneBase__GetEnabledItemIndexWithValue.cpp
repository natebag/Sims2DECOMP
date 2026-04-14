// 0x80084FDC WrapperPaneBase::GetEnabledItemIndexWithValue (88B)
struct PaneItem {
    int m_type;
    int m_flags;
    int m_value;
};

struct WrapperPaneBase {
    char pad[8];
    PaneItem** m_items;
    PaneItem** m_itemsEnd;
    int GetEnabledItemIndexWithValue(int type, int value);
};

int WrapperPaneBase::GetEnabledItemIndexWithValue(int type, int value) {
    int idx = 0;
    for (PaneItem** it = m_items; it != m_itemsEnd; ++it) {
        PaneItem* item = *it;
        if (item->m_type == type && (item->m_flags & 1)) {
            if (item->m_value == value)
                return idx;
            ++idx;
        }
    }
    return -1;
}
