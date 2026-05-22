// 0x803B30DC _Deque_base<int, allocator<int> >::~_Deque_base(void) (128B)

void __builtin_delete(void* p);

struct _NodeAlloc {
    static void _M_deallocate(void* p, unsigned int n);
};

struct _DequeIter {
    int* _M_cur;
    int* _M_first;
    int* _M_last;
    int** _M_node;
};

struct _DequeBaseInt {
    _DequeIter _M_start;
    _DequeIter _M_finish;
    int _pad0;
    int** _M_map;
    int _pad1;
    unsigned int _M_map_size;

    void _M_destroy_nodes(int** first, int** last);
    void dtor(int flags);
};

void _DequeBaseInt::dtor(int flags) {
    if (_M_map) {
        _M_destroy_nodes(_M_start._M_node, _M_finish._M_node + 1);
        int** map = _M_map;
        unsigned int sz = _M_map_size;
        if (map) {
            sz *= 4;
            if (sz > 128)
                __builtin_delete(map);
            else
                _NodeAlloc::_M_deallocate(map, sz);
        }
    }
    if (flags & 1)
        __builtin_delete(this);
}
