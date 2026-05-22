// 0x803B5584 _Deque_base<MMUTarget::MMU_MENU_STATE, allocator<MMUTarget::MMU_MENU_STATE> >::_M_create_nodes(...) (76B)
// ASMPROC_swap_adj: a=mr b=mr which=first
struct _NodeAlloc { static void* _M_allocate(unsigned int n); };
struct _DequeIter { int* a; int* b; int* c; int** d; };
struct _DequeBaseMMU {
    _DequeIter _M_start; _DequeIter _M_finish;
    int _pad0; int** _M_map; int _pad1; unsigned int _M_map_size;
    void _M_create_nodes(int** first, int** last);
    void _M_destroy_nodes(int** first, int** last);
};
void _DequeBaseMMU::_M_create_nodes(int** first, int** last) {
    while (first < last) { *first = (int*)_NodeAlloc::_M_allocate(128); ++first; }
}
