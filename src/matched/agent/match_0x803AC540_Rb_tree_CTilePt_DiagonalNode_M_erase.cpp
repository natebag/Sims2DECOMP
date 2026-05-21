// 0x803AC540 _Rb_tree<CTilePt, pair<CTilePt, pair<DiagonalNode, DiagonalNode>>>::_M_erase (104B)

template <typename T0, typename T1> struct pair;
template <typename T> struct less;
template <typename T> struct allocator;
template <typename T> struct _Select1st;

struct DiagonalNode;

class CTilePt {
public:
    ~CTilePt();
};

template <typename T> struct _Rb_tree_node {};

extern void* __node_alloc_M_deallocate(void* ptr, unsigned int size);

template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
class _Rb_tree {
public:
    void _M_erase(_Rb_tree_node<Value>* __x);
};

template <>
void _Rb_tree<CTilePt, pair<CTilePt, pair<DiagonalNode, DiagonalNode> >, _Select1st<pair<CTilePt, pair<DiagonalNode, DiagonalNode> > >, less<CTilePt>, allocator<pair<CTilePt, pair<DiagonalNode, DiagonalNode> > > >::_M_erase(_Rb_tree_node<pair<CTilePt, pair<DiagonalNode, DiagonalNode> > >* __x) {
    while (__x != 0) {
        _M_erase(*(_Rb_tree_node<pair<CTilePt, pair<DiagonalNode, DiagonalNode> > >**)((char*)__x + 12));
        _Rb_tree_node<pair<CTilePt, pair<DiagonalNode, DiagonalNode> > >* __y = *(_Rb_tree_node<pair<CTilePt, pair<DiagonalNode, DiagonalNode> > >**)((char*)__x + 8);
        ((CTilePt*)((char*)__x + 16))->~CTilePt();
        if (__x) __node_alloc_M_deallocate(__x, 36);
        __x = __y;
    }
}
