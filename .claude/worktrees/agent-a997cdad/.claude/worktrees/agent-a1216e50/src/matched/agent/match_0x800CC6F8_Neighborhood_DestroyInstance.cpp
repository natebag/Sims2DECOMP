/* Neighborhood::DestroyInstance(Neighborhood *) - 0x800CC6F8 (64 bytes) */

struct Neighborhood {
    virtual ~Neighborhood();
    static void DestroyInstance(Neighborhood *p);
};

void Neighborhood::DestroyInstance(Neighborhood *p)
{
    if (p) {
        delete p;
    }
}
