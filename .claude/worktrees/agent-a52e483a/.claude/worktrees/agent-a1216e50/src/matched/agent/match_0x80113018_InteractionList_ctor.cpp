/* InteractionList::InteractionList(void) - 0x80113018 - 20 bytes */

class InteractionList {
public:
    int m_field0;
    int m_size;

    InteractionList(void);
};

InteractionList::InteractionList(void) : m_size(0), m_field0(0) {
}
