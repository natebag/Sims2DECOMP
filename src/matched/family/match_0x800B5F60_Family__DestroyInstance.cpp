// 0x800B5F60 Family::DestroyInstance (64B)

struct Family {
    virtual ~Family();
    static void DestroyInstance(Family *p);
};

void Family::DestroyInstance(Family *p) {
    if (p) {
        delete p;
    }
}
