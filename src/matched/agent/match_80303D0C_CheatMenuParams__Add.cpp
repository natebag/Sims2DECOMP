// 0x80303D0C (60 bytes)
// CheatMenuParams::Add(EDebugMenuItem &)

struct EDebugMenuItem {
    EDebugMenuItem* m_prev;
    EDebugMenuItem* m_next;
};

struct CheatMenuParams {
    EDebugMenuItem* m_head;
    EDebugMenuItem* m_tail;
    int m_count;
    void Add(EDebugMenuItem& item);
};

void CheatMenuParams::Add(EDebugMenuItem& item) {
    item.m_prev = m_tail;
    if (m_tail != 0) {
        m_tail->m_next = &item;
    } else {
        m_head = &item;
    }
    item.m_next = 0;
    m_tail = &item;
    m_count++;
}
