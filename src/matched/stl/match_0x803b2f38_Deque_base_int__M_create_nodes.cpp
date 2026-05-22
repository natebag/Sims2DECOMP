// 0x803B2F38 _Deque_base<int, allocator<int> >::_M_create_nodes(int **, int **) (76B)
// ASMPROC_swap_adj: a=mr b=mr which=first

struct _NodeAlloc {
    static void* _M_allocate(unsigned int n);
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

    void _M_create_nodes(int** first, int** last);
    void _M_destroy_nodes(int** first, int** last);
};

void _DequeBaseInt::_M_create_nodes(int** first, int** last) {
    while (first < last) {
        *first = (int*)_NodeAlloc::_M_allocate(128);
        ++first;
    }
}
