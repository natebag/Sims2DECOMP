// 0x800B6AEC Family::Family (20b)

extern int Family_vtable[];

struct Family {
    int* m_vt;
    Family();
};

Family::Family() {
    *(int**)this = Family_vtable;
}
