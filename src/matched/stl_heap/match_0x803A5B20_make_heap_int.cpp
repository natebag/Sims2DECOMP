// 0x803A5B20 make_heap<int*, bool (*)(int&, int&)> (128B)
typedef bool (*CmpFn_int)(int&, int&);
extern void __adjust_heap_int(int* first, int hole, int len, int value, CmpFn_int cmp);

void make_heap_int(int* first, int* last, CmpFn_int cmp) {
    int count = last - first;
    if (count <= 1) return;
    int parent = (count - 2) / 2;
    do {
        int value = first[parent];
        __adjust_heap_int(first, parent, count, value, cmp);
        if (parent == 0) return;
        parent = parent - 1;
    } while (1);
}
