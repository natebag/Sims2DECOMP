/* House::DestroyInstance(House *) - 0x800BB380 (64 bytes) */

struct House {
    virtual ~House();
    static void DestroyInstance(House *p);
};

void House::DestroyInstance(House *p)
{
    if (p) {
        delete p;
    }
}
