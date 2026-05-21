// 0x800B90F8 cGZSndSys::removeFromList(cGZMusic*) (84B)
// TRIAGE

class cGZMusic {
public:
    char pad_00[36];
    cGZMusic* m_next;
};

class cGZSndSys {
public:
    char pad_00[1032];
    cGZMusic* m_head;
    cGZMusic* m_tail;
    void removeFromList(cGZMusic* m);
};

void cGZSndSys::removeFromList(cGZMusic* m) {
    cGZMusic* p = m_head;
    cGZMusic* prev = 0;
    if (p != m) {
        do {
            prev = p;
            p = prev->m_next;
        } while (p != m);
    }
    if (prev != 0) {
        prev->m_next = m->m_next;
    } else {
        m_head = m->m_next;
    }
    if (m_tail != m) return;
    m_tail = 0;
}
