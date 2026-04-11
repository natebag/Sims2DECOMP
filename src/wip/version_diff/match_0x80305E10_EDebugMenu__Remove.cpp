/* EDebugMenu::Remove(EDebugMenuItem &) at 0x80305E10 (128 bytes) */

struct EDebugMenuItem {
    EDebugMenuItem* m_next;
    EDebugMenuItem* m_prev;
};

struct EDebugMenuList {
    EDebugMenuItem* m_first;
    EDebugMenuItem* m_last;
};

struct EDebugMenu {
    int m_pad_00;
    int m_pad_04;
    int m_active;
    EDebugMenuList m_list;
    int m_selectedIndex;
    int m_count;

    void Remove(EDebugMenuItem& item);
};

void EDebugMenu::Remove(EDebugMenuItem& item) {
    EDebugMenuList* pList = &m_list;

    if (pList->m_first == &item) {
        pList->m_first = item.m_prev;
    } else {
        item.m_next->m_prev = item.m_prev;
    }

    if (pList->m_last == &item) {
        pList->m_last = item.m_next;
    } else {
        item.m_prev->m_next = item.m_next;
    }

    m_active = 1;
    m_count = m_count - 1;
    if (m_count == 0) return;
    if (m_selectedIndex < m_count) return;
    m_selectedIndex = m_selectedIndex - 1;
}
