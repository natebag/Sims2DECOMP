// 0x803A5BA0 pop_heap<int*, bool (*)(int&, int&)> (64B)
typedef bool (*CmpFn_int)(int&, int&);
extern void __adjust_heap_int(int* first, int hole, int len, int value, CmpFn_int cmp);
void pop_heap_int(int* first, int* last, CmpFn_int cmp) {
    int* last_m1 = last - 1;
    int value = *last_m1;
    *last_m1 = *first;
    __adjust_heap_int(first, 0, last_m1 - first, value, cmp);
}
