typedef unsigned int size_t;
void* operator new(size_t, void*);

struct ERFlash {
    char pad[24];
    ERFlash();
    static void Construct(ERFlash* obj);
};

void ERFlash::Construct(ERFlash* obj) {
    new (obj) ERFlash();
}
