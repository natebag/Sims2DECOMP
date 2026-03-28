typedef unsigned int size_t;
void* operator new(size_t, void*);

struct ERTexture {
    char pad[24];
    ERTexture();
    static void Construct(ERTexture* obj);
};

void ERTexture::Construct(ERTexture* obj) {
    new (obj) ERTexture();
}
