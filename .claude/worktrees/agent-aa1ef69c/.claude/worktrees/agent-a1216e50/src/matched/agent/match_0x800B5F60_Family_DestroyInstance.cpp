/* Family::DestroyInstance(Family *) - 0x800B5F60 (64 bytes) */

struct Family {
    virtual ~Family();
    static void DestroyInstance(Family *p);
};

void Family::DestroyInstance(Family *p)
{
    if (p) {
        delete p;
    }
}
