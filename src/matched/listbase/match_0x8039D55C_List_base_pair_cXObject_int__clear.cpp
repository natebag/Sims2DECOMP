// 0x8039D55C _List_base<pair<cXObject *, int>, allocator<pair<cXObject *, int>>>::clear (108B)

struct _List_node_base {
    _List_node_base *m_next;
    _List_node_base *m_prev;
};

template<typename T>
struct _List_node : _List_node_base {
    T m_data;
};

template<typename T>
struct _List_base {
    char _pad[4];
    _List_node_base *m_head;
    void clear(void);
};

extern void _List_dealloc(void *p, int size);

template<typename T>
void _List_base<T>::clear(void) {
    _List_node_base *cur = m_head->m_next;
    while (cur != m_head) {
        _List_node<T> *node = (_List_node<T> *)cur;
        cur = cur->m_next;
        if (node)
            _List_dealloc(node, sizeof(_List_node<T>));
    }
    m_head->m_next = m_head;
    m_head->m_prev = m_head;
}

struct pair_cXObject_int { void *first; int second; };

template void _List_base<pair_cXObject_int>::clear(void);
