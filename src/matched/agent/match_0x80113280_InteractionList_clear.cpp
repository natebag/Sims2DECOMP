/* InteractionList::clear(void) - 0x80113280 - 112 bytes */

struct ILNode {
    ILNode *m_next;
    int _pad1;
    int _pad2;
    int _pad3;
    int _pad4;
    int _pad5;
    int _pad6;
    int _pad7;
    int _pad8;
    int _pad9;
    int _pad10;
    int _pad11;
    int _pad12;
    int _pad13;
    int _pad14;
    int _pad15;
    virtual ~ILNode(void);
};

struct InteractionList {
    ILNode *m_head;
    ILNode *m_tail;

    void clear(void);
};

void InteractionList::clear(void) {
    ILNode *next = m_head;
    while (next != 0) {
        ILNode *cur = next;
        next = cur->m_next;
        if (cur != 0) {
            delete cur;
        }
    }
    m_tail = 0;
    m_head = 0;
}
