/* InteractionList::remove(InteractionList::iterator &) - 0x80113174 - 268 bytes */

struct ILNode {
    ILNode *m_link;
    int _pad1; int _pad2; int _pad3; int _pad4; int _pad5;
    int _pad6; int _pad7; int _pad8; int _pad9; int _pad10;
    int _pad11; int _pad12; int _pad13; int _pad14; int _pad15;
    virtual ~ILNode(void);
};

struct InteractionList {
    ILNode *m_head;
    ILNode *m_tail;
    struct iterator {
        ILNode *m_current;
    };
    void remove(InteractionList::iterator &iter);
};

void InteractionList::remove(InteractionList::iterator &iter) {
    ILNode *node = iter.m_current;
    if (m_head == node) {
        ILNode *next = node->m_link;
        if (node != 0) {
            delete node;
        }
        m_head = next;
        if (m_tail == iter.m_current) {
            m_tail = 0;
        }
    } else {
        ILNode *pred = m_head;
        if (pred != 0) {
            for (; pred->m_link != iter.m_current; pred = pred->m_link) {
                if (pred->m_link == 0) {
                    pred = pred->m_link;
                    return;
                }
            }
            if (pred != 0) {
                ILNode *cur = pred->m_link;
                ILNode *next;
                if (cur != 0) {
                    next = cur->m_link;
                } else {
                    next = cur;
                }
                if (cur != 0) {
                    delete cur;
                }
                pred->m_link = next;
                if (m_tail == iter.m_current) {
                    m_tail = pred;
                }
            }
        }
    }
}
