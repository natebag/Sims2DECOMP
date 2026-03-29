/* InteractionList::push_back(cXPerson *, cXObject *, int, int) - 0x801130F8 - 124 bytes */

struct cXPerson;
struct cXObject;

struct Interaction {
    Interaction *m_link;
    int _data[16];
    Interaction(cXPerson *person, cXObject *obj, int a, int b);
};

struct InteractionList {
    Interaction *m_head;
    Interaction *m_tail;

    void push_back(cXPerson *person, cXObject *obj, int a, int b);
};

void InteractionList::push_back(cXPerson *person, cXObject *obj, int a, int b) {
    Interaction *node = new Interaction(person, obj, a, b);
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
