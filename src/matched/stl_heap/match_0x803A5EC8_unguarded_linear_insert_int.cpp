// 0x803A5EC8 __unguarded_linear_insert<int*, int, bool (*)(int&, int&)> (108B)

typedef bool (*CmpFnInt)(int&, int&);

void __unguarded_linear_insert_int(int* last, int value, CmpFnInt cmp) {
    int* next = last - 1;
    while (cmp(value, *next)) {
        *last = *next;
        last = next;
        next = last - 1;
    }
    *last = value;
}
