// 0x800BC9D0 IconGroup::DestroyInstance (64B)

struct IconGroup {
    virtual ~IconGroup();
    static void DestroyInstance(IconGroup *p);
};

void IconGroup::DestroyInstance(IconGroup *p) {
    if (p) {
        delete p;
    }
}
