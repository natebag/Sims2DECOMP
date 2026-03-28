/* Family::Family(void) at 0x800B6AEC (20B) */

extern int Family_vtable[];

struct Family {
    int* m_vtable;

    Family(void);
};

Family::Family(void) {
    m_vtable = Family_vtable;
}
