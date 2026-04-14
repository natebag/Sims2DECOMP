// 0x80134AA8 RelMatrix::DestroyInstance (64B)

struct RelMatrix {
    virtual ~RelMatrix();
    static void DestroyInstance(RelMatrix *p);
};

void RelMatrix::DestroyInstance(RelMatrix *p) {
    if (p) {
        delete p;
    }
}
