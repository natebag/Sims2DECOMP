/* InteractionList::size(void) const - 0x8011306C - 40 bytes */

struct InteractionListNode {
    InteractionListNode* next;
};

struct InteractionList {
    InteractionListNode* head;

    int size(void) const;
};

int InteractionList::size(void) const {
    InteractionListNode* node = head;
    int count = 0;
    while (node != 0) {
        node = node->next;
        count++;
    }
    return count;
}
