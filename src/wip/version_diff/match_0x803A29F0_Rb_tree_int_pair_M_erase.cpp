template <typename T0, typename T1> struct pair;
template <typename T> struct less;
template <typename T> struct allocator;
template <typename T> struct _Select1st;

template <typename T> struct _Rb_tree_node {
};

extern void* __node_alloc_M_deallocate(void* ptr, unsigned int size);

template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
class _Rb_tree {
public:
    void _M_erase(_Rb_tree_node<Value>* __x);
};

template <>
void _Rb_tree<int, pair<int, int>, _Select1st<pair<int, int> >, less<int>, allocator<pair<int, int> > >::_M_erase(_Rb_tree_node<pair<int, int> > * __x) {
    while (__x != 0) {
        _M_erase(*(_Rb_tree_node<pair<int, int> >**)((char*)__x + 12));
        _Rb_tree_node<pair<int, int> >* __y = *(_Rb_tree_node<pair<int, int> >**)((char*)__x + 8);
        if (__x) __node_alloc_M_deallocate(__x, 24);
        __x = __y;
    }
}
