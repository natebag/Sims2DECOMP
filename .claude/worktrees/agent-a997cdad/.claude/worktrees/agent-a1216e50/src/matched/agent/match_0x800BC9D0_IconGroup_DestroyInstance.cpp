/* IconGroup::DestroyInstance(IconGroup *) - 0x800BC9D0 (64 bytes) */

struct IconGroup {
    virtual ~IconGroup();
    static void DestroyInstance(IconGroup *p);
};

void IconGroup::DestroyInstance(IconGroup *p)
{
    if (p) {
        delete p;
    }
}
