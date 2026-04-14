// 0x8039DFE4 __unguarded_linear_insert<unsigned int*, unsigned int, bool (*)(unsigned int&, unsigned int&)> (108B)

typedef bool (*CmpFnUint)(unsigned int&, unsigned int&);

void __unguarded_linear_insert_uint(unsigned int* last, unsigned int value, CmpFnUint cmp) {
    unsigned int* next = last - 1;
    while (cmp(value, *next)) {
        *last = *next;
        last = next;
        next = last - 1;
    }
    *last = value;
}
