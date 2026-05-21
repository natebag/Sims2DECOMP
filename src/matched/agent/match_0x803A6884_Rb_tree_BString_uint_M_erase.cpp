// 0x803A6884 _Rb_tree<BString, pair<BString, unsigned int>>::_M_erase (104B)

template <typename T0, typename T1> struct pair;
template <typename T> struct less;
template <typename T> struct allocator;
template <typename T> struct _Select1st;

class BString {
public:
    ~BString();
};

template <typename T> struct _Rb_tree_node {};

extern void* __node_alloc_M_deallocate(void* ptr, unsigned int size);

template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
class _Rb_tree {
public:
    void _M_erase(_Rb_tree_node<Value>* __x);
};

template <>
void _Rb_tree<BString, pair<BString, unsigned int>, _Select1st<pair<BString, unsigned int> >, less<BString>, allocator<pair<BString, unsigned int> > >::_M_erase(_Rb_tree_node<pair<BString, unsigned int> >* __x) {
    while (__x != 0) {
        _M_erase(*(_Rb_tree_node<pair<BString, unsigned int> >**)((char*)__x + 12));
        _Rb_tree_node<pair<BString, unsigned int> >* __y = *(_Rb_tree_node<pair<BString, unsigned int> >**)((char*)__x + 8);
        ((BString*)((char*)__x + 16))->~BString();
        if (__x) __node_alloc_M_deallocate(__x, 24);
        __x = __y;
    }
}
