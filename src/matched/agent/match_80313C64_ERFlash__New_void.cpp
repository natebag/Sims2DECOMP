typedef unsigned int size_t;

struct ERFlash {
    char pad[24];
    void* operator new(size_t);
    ERFlash();
    static ERFlash* New();
};

ERFlash* ERFlash::New() {
    return new ERFlash();
}
