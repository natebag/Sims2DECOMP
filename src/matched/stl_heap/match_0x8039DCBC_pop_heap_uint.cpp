// 0x8039DCBC pop_heap<unsigned int*, bool (*)(unsigned int&, unsigned int&)> (64B)
typedef bool (*CmpFn_uint)(unsigned int&, unsigned int&);
extern void __adjust_heap_uint(unsigned int* first, int hole, int len, unsigned int value, CmpFn_uint cmp);
void pop_heap_uint(unsigned int* first, unsigned int* last, CmpFn_uint cmp) {
    unsigned int* last_m1 = last - 1;
    unsigned int value = *last_m1;
    *last_m1 = *first;
    __adjust_heap_uint(first, 0, last_m1 - first, value, cmp);
}
