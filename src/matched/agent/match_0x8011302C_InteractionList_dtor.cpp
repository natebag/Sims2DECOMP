/* InteractionList::~InteractionList(void) - 0x8011302C - 64 bytes */

void __builtin_delete(void *);

struct InteractionList {
    void *m_head;
    void *m_tail;

    void clear(void);
    void dtor(int flags);
};

void InteractionList::dtor(int flags) {
    clear();
    if (flags & 1) {
        __builtin_delete(this);
    }
}
