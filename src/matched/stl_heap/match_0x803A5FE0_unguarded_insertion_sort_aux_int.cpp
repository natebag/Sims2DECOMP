// 0x803A5FE0 __unguarded_insertion_sort_aux<int*, int, bool (*)(int&, int&)> (84B)

typedef bool (*CmpFnInt)(int&, int&);

extern void __unguarded_linear_insert_int(int* last, int value, CmpFnInt cmp);

void __unguarded_insertion_sort_aux_int(int* first, int* last, int* /*unused*/, CmpFnInt cmp) {
    int* end = last;
    int* i = first;
    if (i == end) return;
    do {
        __unguarded_linear_insert_int(i, *i, cmp);
        ++i;
    } while (i != end);
}
