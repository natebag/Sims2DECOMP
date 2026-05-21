// 0x800B90F8 cGZSndSys::removeFromList(cGZMusic*) (84B)
// Same singly-linked search+excise as removeFromList(cGZSnd*),
// but list head at +0x408, next at node+0x24, plus tail ptr at +0x40c cleared on removal.

class cGZMusic {
public:
    char _pad[0x24];
    cGZMusic* m_next;
};

class cGZSndSys_RM {
public:
    char _pad[0x408];
    cGZMusic* m_musicHead;   // +0x408
    cGZMusic* m_musicTail;   // +0x40c
    void removeFromList(cGZMusic* node);
};

void cGZSndSys_RM::removeFromList(cGZMusic* node) {
    cGZMusic* cur = m_musicHead;
    cGZMusic* prev = 0;
    if (cur != node) {
        do {
            prev = cur;
            cur = prev->m_next;
        } while (cur != node);
    }
    if (prev != 0) {
        prev->m_next = node->m_next;
    } else {
        m_musicHead = node->m_next;
    }
    if (m_musicTail != node) return;
    m_musicTail = 0;
}
