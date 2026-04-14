// 0x803A6034 __final_insertion_sort<int*, bool (*)(int&, int&)> (108B)
typedef bool (*CmpFn_int)(int&, int&);
extern void __insertion_sort_int(int* first, int* last, CmpFn_int cmp);
extern void __unguarded_insertion_sort_aux_int(int* first, int* last, int* dummy, CmpFn_int cmp);

void __final_insertion_sort_int(int* first, int* last, CmpFn_int cmp) {
    int count = last - first;
    if (count > 16) {
        int* mid = first + 16;
        __insertion_sort_int(first, mid, cmp);
        __unguarded_insertion_sort_aux_int(mid, last, (int*)0, cmp);
    } else {
        __insertion_sort_int(first, last, cmp);
    }
}
