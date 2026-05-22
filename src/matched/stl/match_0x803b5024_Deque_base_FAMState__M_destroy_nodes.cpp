// 0x803B5024 _Deque_base<FAMTarget::FAM_STATE, allocator<FAMTarget::FAM_STATE> >::_M_destroy_nodes(...) (84B)
// ASMPROC_swap_adj: a=mr b=mr which=first

struct _NodeAlloc { static void _M_deallocate(void* p, unsigned int n); };
struct _DequeIter { int* a; int* b; int* c; int** d; };
struct _DequeBaseFAM {
    _DequeIter _M_start; _DequeIter _M_finish;
    int _pad0; int** _M_map; int _pad1; unsigned int _M_map_size;
    void _M_create_nodes(int** first, int** last);
    void _M_destroy_nodes(int** first, int** last);
};
void _DequeBaseFAM::_M_destroy_nodes(int** first, int** last) {
    while (first < last) { if (*first) _NodeAlloc::_M_deallocate(*first, 128); ++first; }
}
