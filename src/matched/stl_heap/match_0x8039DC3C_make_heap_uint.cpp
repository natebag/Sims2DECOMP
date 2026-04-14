// 0x8039DC3C make_heap<unsigned int*, bool (*)(unsigned int&, unsigned int&)> (128B)
typedef bool (*CmpFn_uint)(unsigned int&, unsigned int&);
extern void __adjust_heap_uint(unsigned int* first, int hole, int len, unsigned int value, CmpFn_uint cmp);

void make_heap_uint(unsigned int* first, unsigned int* last, CmpFn_uint cmp) {
    int count = last - first;
    if (count <= 1) return;
    int parent = (count - 2) / 2;
    do {
        unsigned int value = first[parent];
        __adjust_heap_uint(first, parent, count, value, cmp);
        if (parent == 0) return;
        parent = parent - 1;
    } while (1);
}
