/* InteractionList::increment(InteractionList::iterator &) - 0x801132F0 - 24 bytes */
/* lwz r9, 0(r3); cmpwi r9, 0; beqlr; lwz r0, 0(r9); stw r0, 0(r3); blr */

struct InteractionNode {
    InteractionNode* m_next;
};

struct InteractionListIterator {
    InteractionNode* m_current;
};

void InteractionList_increment(InteractionListIterator &it) {
    InteractionNode* node = it.m_current;
    if (node != 0) {
        it.m_current = node->m_next;
    }
}
