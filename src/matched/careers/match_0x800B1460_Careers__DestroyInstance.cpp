// 0x800B1460 Careers::DestroyInstance (64B)

struct Careers {
    virtual ~Careers();
    static void DestroyInstance(Careers *p);
};

void Careers::DestroyInstance(Careers *p) {
    if (p) {
        delete p;
    }
}
