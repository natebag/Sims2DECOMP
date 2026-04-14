// 0x800BB380 House::DestroyInstance (64B)

struct House {
    virtual ~House();
    static void DestroyInstance(House *p);
};

void House::DestroyInstance(House *p) {
    if (p) {
        delete p;
    }
}
