/* InteractionList::push_back(Interaction &) - 0x80113094 - 100 bytes */

struct Interaction {
    Interaction *m_link;
    int _data[16];
    Interaction(Interaction &src);
};

struct InteractionList {
    Interaction *m_head;
    Interaction *m_tail;

    void push_back(Interaction &src);
};

void InteractionList::push_back(Interaction &src) {
    Interaction *node = new Interaction(src);
    node->m_link = 0;
    Interaction *tail = m_tail;
    if (tail != 0) {
        tail->m_link = node;
        m_tail = node;
    } else {
        m_head = node;
        m_tail = node;
    }
}
