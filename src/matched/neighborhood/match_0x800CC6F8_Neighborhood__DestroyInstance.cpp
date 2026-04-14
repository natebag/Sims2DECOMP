// 0x800CC6F8 Neighborhood::DestroyInstance (64B)

struct Neighborhood {
    virtual ~Neighborhood();
    static void DestroyInstance(Neighborhood *p);
};

void Neighborhood::DestroyInstance(Neighborhood *p) {
    if (p) {
        delete p;
    }
}
