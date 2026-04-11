struct CasMediator;

struct CasListener {
    void* m_pMediator;
    virtual ~CasListener();
    virtual void HandleEvent(void*);
    virtual void SetMediator(CasMediator*);
};

struct _Rb_tree_node_base;

struct _Rb_tree_base_iterator {
    _Rb_tree_node_base* _M_node;
};

struct _Rb_tree_iterator : public _Rb_tree_base_iterator {
    _Rb_tree_iterator() {}
    _Rb_tree_iterator(const _Rb_tree_iterator& x) { _M_node = x._M_node; }
};

template <class T1, class T2>
struct pair {
    T1 first;
    T2 second;
    pair() : first(), second() {}
    pair(const T1& a, const T2& b) : first(a), second(b) {}
    pair(const pair& p) : first(p.first), second(p.second) {}
};

typedef pair<_Rb_tree_iterator, bool> pair_ib;

struct CasListenerSet {
    int _M_alloc;
    void* _M_header;
    int _M_node_count;
    char _M_key_compare;

    pair_ib insert_unique(CasListener* const &);
};

struct CasMediator : CasListenerSet {
    void AddListener(CasListener& listener);
};

void CasMediator::AddListener(CasListener& listener) {
    CasListener* p = &listener;
    pair_ib result = insert_unique(p);
    listener.SetMediator(this);
}
