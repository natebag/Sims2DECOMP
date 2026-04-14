// 0x8039E150 __final_insertion_sort<unsigned int*, bool (*)(unsigned int&, unsigned int&)> (108B)
typedef bool (*CmpFn_uint)(unsigned int&, unsigned int&);
extern void __insertion_sort_uint(unsigned int* first, unsigned int* last, CmpFn_uint cmp);
extern void __unguarded_insertion_sort_aux_uint(unsigned int* first, unsigned int* last, unsigned int* dummy, CmpFn_uint cmp);

void __final_insertion_sort_uint(unsigned int* first, unsigned int* last, CmpFn_uint cmp) {
    int count = last - first;
    if (count > 16) {
        unsigned int* mid = first + 16;
        __insertion_sort_uint(first, mid, cmp);
        __unguarded_insertion_sort_aux_uint(mid, last, (unsigned int*)0, cmp);
    } else {
        __insertion_sort_uint(first, last, cmp);
    }
}
