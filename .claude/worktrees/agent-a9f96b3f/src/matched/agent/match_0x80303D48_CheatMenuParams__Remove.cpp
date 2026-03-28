/* CheatMenuParams::Remove(EDebugMenuItem &) at 0x80303D48 (100 bytes) */

struct EDebugMenuItem {
    EDebugMenuItem* m_next;
    EDebugMenuItem* m_prev;
};

struct CheatMenuParams {
    EDebugMenuItem* m_first;
    EDebugMenuItem* m_last;
    int m_count;

    void Remove(EDebugMenuItem& item);
};

void CheatMenuParams::Remove(EDebugMenuItem& item) {
    if (m_count == 0) return;

    if (m_first == &item) {
        m_first = item.m_prev;
    } else {
        item.m_next->m_prev = item.m_prev;
    }

    if (m_last == &item) {
        m_last = item.m_next;
    } else {
        item.m_prev->m_next = item.m_next;
    }

    m_count = m_count - 1;
}
