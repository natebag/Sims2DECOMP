// 0x803AE964 _Rb_tree<pair<uint,ObjectDataID>, pair<pair<uint,ObjectDataID>, tDataProvider>>::_M_erase (92B)

template <typename T0, typename T1> struct pair;
template <typename T> struct less;
template <typename T> struct allocator;
template <typename T> struct _Select1st;

struct ObjectDataID;

class ISmartDataFactory {
public:
    struct tDataProvider;
};

template <typename T> struct _Rb_tree_node {};

extern void* __node_alloc_M_deallocate(void* ptr, unsigned int size);

template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
class _Rb_tree {
public:
    void _M_erase(_Rb_tree_node<Value>* __x);
};

template <>
void _Rb_tree<pair<unsigned int, ObjectDataID>, pair<pair<unsigned int, ObjectDataID>, ISmartDataFactory::tDataProvider>, _Select1st<pair<pair<unsigned int, ObjectDataID>, ISmartDataFactory::tDataProvider> >, less<pair<unsigned int, ObjectDataID> >, allocator<pair<pair<unsigned int, ObjectDataID>, ISmartDataFactory::tDataProvider> > >::_M_erase(_Rb_tree_node<pair<pair<unsigned int, ObjectDataID>, ISmartDataFactory::tDataProvider> >* __x) {
    while (__x != 0) {
        _M_erase(*(_Rb_tree_node<pair<pair<unsigned int, ObjectDataID>, ISmartDataFactory::tDataProvider> >**)((char*)__x + 12));
        _Rb_tree_node<pair<pair<unsigned int, ObjectDataID>, ISmartDataFactory::tDataProvider> >* __y = *(_Rb_tree_node<pair<pair<unsigned int, ObjectDataID>, ISmartDataFactory::tDataProvider> >**)((char*)__x + 8);
        if (__x) __node_alloc_M_deallocate(__x, 32);
        __x = __y;
    }
}
