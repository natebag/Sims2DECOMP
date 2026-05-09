// 0x800B90A8 (64B) cGZSndSys::removeFromList(cGZSnd*)
// Linked-list remove: head at this+1028, next at node+60.
// Walks list to find predecessor, then excises target.

class cGZSnd {
public:
    char _pad[60];
    cGZSnd* m_next;  // +60
};

class cGZSndSys {
public:
    char _pad[1028];
    cGZSnd* m_head;  // +1028
    void removeFromList(cGZSnd* node);
};

void cGZSndSys::removeFromList(cGZSnd* node)
{
    cGZSnd* cur = m_head;
    cGZSnd* prev = 0;
    if (cur != node) {
        do {
            prev = cur;
            cur = prev->m_next;
        } while (cur != node);
    }
    if (prev != 0) {
        prev->m_next = node->m_next;
    } else {
        m_head = node->m_next;
    }
}
