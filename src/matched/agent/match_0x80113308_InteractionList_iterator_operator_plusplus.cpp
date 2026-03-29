/* InteractionList::iterator::operator++(void) - 0x80113308 - 52 bytes */

struct ILNode {
    ILNode *m_link;
};

struct iterator {
    ILNode *m_current;
    ILNode *operator++(void);
};

void InteractionList_increment(iterator &iter);

ILNode *iterator::operator++(void) {
    ILNode *old = m_current;
    InteractionList_increment(*this);
    return old;
}
