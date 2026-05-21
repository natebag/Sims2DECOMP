// 0x803A68EC _Rb_tree<unsigned int, pair<unsigned int, iResFile*>>::_M_erase (92B)

template <typename T0, typename T1> struct pair;
template <typename T> struct less;
template <typename T> struct allocator;
template <typename T> struct _Select1st;

class iResFile;

template <typename T> struct _Rb_tree_node {};

extern void* __node_alloc_M_deallocate(void* ptr, unsigned int size);

template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
class _Rb_tree {
public:
    void _M_erase(_Rb_tree_node<Value>* __x);
};

template <>
void _Rb_tree<unsigned int, pair<unsigned int, iResFile*>, _Select1st<pair<unsigned int, iResFile*> >, less<unsigned int>, allocator<pair<unsigned int, iResFile*> > >::_M_erase(_Rb_tree_node<pair<unsigned int, iResFile*> >* __x) {
    while (__x != 0) {
        _M_erase(*(_Rb_tree_node<pair<unsigned int, iResFile*> >**)((char*)__x + 12));
        _Rb_tree_node<pair<unsigned int, iResFile*> >* __y = *(_Rb_tree_node<pair<unsigned int, iResFile*> >**)((char*)__x + 8);
        if (__x) __node_alloc_M_deallocate(__x, 24);
        __x = __y;
    }
}
