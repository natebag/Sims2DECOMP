// 0x803A6948 _Rb_tree<uint, pair<uint, NamespaceSelector>>::_M_erase (104B)

template <typename T0, typename T1> struct pair;
template <typename T> struct less;
template <typename T> struct allocator;
template <typename T> struct _Select1st;

class NamespaceSelector {
public:
    ~NamespaceSelector();
};

template <typename T> struct _Rb_tree_node {};

extern void* __node_alloc_M_deallocate(void* ptr, unsigned int size);

template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
class _Rb_tree {
public:
    void _M_erase(_Rb_tree_node<Value>* __x);
};

template <>
void _Rb_tree<unsigned int, pair<unsigned int, NamespaceSelector>, _Select1st<pair<unsigned int, NamespaceSelector> >, less<unsigned int>, allocator<pair<unsigned int, NamespaceSelector> > >::_M_erase(_Rb_tree_node<pair<unsigned int, NamespaceSelector> >* __x) {
    while (__x != 0) {
        _M_erase(*(_Rb_tree_node<pair<unsigned int, NamespaceSelector> >**)((char*)__x + 12));
        _Rb_tree_node<pair<unsigned int, NamespaceSelector> >* __y = *(_Rb_tree_node<pair<unsigned int, NamespaceSelector> >**)((char*)__x + 8);
        ((NamespaceSelector*)((char*)__x + 20))->~NamespaceSelector();
        if (__x) __node_alloc_M_deallocate(__x, 72);
        __x = __y;
    }
}
