/* Careers::DestroyInstance(Careers *) - 0x800B1460 (64 bytes) */

struct Careers {
    virtual ~Careers();
    static void DestroyInstance(Careers *p);
};

void Careers::DestroyInstance(Careers *p)
{
    if (p) {
        delete p;
    }
}
