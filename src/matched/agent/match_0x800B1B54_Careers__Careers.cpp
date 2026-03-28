/* Careers::Careers(void) at 0x800B1B54 (20B) */

extern int Careers_vtable[];

struct Careers {
    int* m_vtable;

    Careers(void);
};

Careers::Careers(void) {
    m_vtable = Careers_vtable;
}
