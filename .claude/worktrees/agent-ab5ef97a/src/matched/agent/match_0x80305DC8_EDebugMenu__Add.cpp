/* EDebugMenu::Add(EDebugMenuItem &) at 0x80305DC8 (72 bytes) */

typedef unsigned int u32;

struct EDebugMenuItem {
    EDebugMenuItem* m_next;
    EDebugMenuItem* m_prev;
};

struct EDebugMenuList {
    EDebugMenuItem* m_first;
    EDebugMenuItem* m_last;
};

struct EDebugMenu {
    u32 m_pad_00;
    u32 m_pad_04;
    u32 m_active;
    EDebugMenuList m_list;
    u32 m_pad_14;
    u32 m_count;

    void Add(EDebugMenuItem& item);
};

void EDebugMenu::Add(EDebugMenuItem& item) {
    EDebugMenuList* pList = &m_list;
    EDebugMenuItem* pOld = pList->m_last;
    item.m_next = pOld;
    if (pList->m_last) {
        pList->m_last->m_prev = &item;
    } else {
        pList->m_first = &item;
    }
    item.m_prev = (EDebugMenuItem*)0;
    pList->m_last = &item;
    m_active = 1;
    m_count++;
}
