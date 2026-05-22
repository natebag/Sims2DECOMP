// 0x803B4ED4 _Deque_base<FAMTarget::FAM_STATE, allocator<FAMTarget::FAM_STATE> >::_M_create_nodes(...) (76B)
// ASMPROC_swap_adj: a=mr b=mr which=first

struct _NodeAlloc { static void* _M_allocate(unsigned int n); };
struct _DequeIter { int* a; int* b; int* c; int** d; };
struct _DequeBaseFAM {
    _DequeIter _M_start; _DequeIter _M_finish;
    int _pad0; int** _M_map; int _pad1; unsigned int _M_map_size;
    void _M_create_nodes(int** first, int** last);
    void _M_destroy_nodes(int** first, int** last);
};
void _DequeBaseFAM::_M_create_nodes(int** first, int** last) {
    while (first < last) { *first = (int*)_NodeAlloc::_M_allocate(128); ++first; }
}
