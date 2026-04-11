// 0x800B1B54 Careers::Careers (20b)

extern int Careers_vtable[];

struct Careers {
    int* m_vt;
    Careers();
};

Careers::Careers() {
    *(int**)this = Careers_vtable;
}
