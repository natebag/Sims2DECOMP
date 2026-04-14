// 0x8039E0FC __unguarded_insertion_sort_aux<unsigned int*, unsigned int, bool (*)(unsigned int&, unsigned int&)> (84B)

typedef bool (*CmpFnUint)(unsigned int&, unsigned int&);

extern void __unguarded_linear_insert_uint(unsigned int* last, unsigned int value, CmpFnUint cmp);

void __unguarded_insertion_sort_aux_uint(unsigned int* first, unsigned int* last, unsigned int* /*unused*/, CmpFnUint cmp) {
    unsigned int* end = last;
    unsigned int* i = first;
    if (i == end) return;
    do {
        __unguarded_linear_insert_uint(i, *i, cmp);
        ++i;
    } while (i != end);
}
