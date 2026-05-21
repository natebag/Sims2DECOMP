// 0x803B0AC0 _Rb_tree<CasListener*, CasListener*, _Identity>::_M_erase (92B) — set, not map

template <typename T> struct less;
template <typename T> struct allocator;
template <typename T> struct _Identity;

class CasListener;

template <typename T> struct _Rb_tree_node {};

extern void* __node_alloc_M_deallocate(void* ptr, unsigned int size);

template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
class _Rb_tree {
public:
    void _M_erase(_Rb_tree_node<Value>* __x);
};

template <>
void _Rb_tree<CasListener*, CasListener*, _Identity<CasListener*>, less<CasListener*>, allocator<CasListener*> >::_M_erase(_Rb_tree_node<CasListener*>* __x) {
    while (__x != 0) {
        _M_erase(*(_Rb_tree_node<CasListener*>**)((char*)__x + 12));
        _Rb_tree_node<CasListener*>* __y = *(_Rb_tree_node<CasListener*>**)((char*)__x + 8);
        if (__x) __node_alloc_M_deallocate(__x, 20);
        __x = __y;
    }
}
