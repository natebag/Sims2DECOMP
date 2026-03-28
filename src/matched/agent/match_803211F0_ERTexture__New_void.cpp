typedef unsigned int size_t;

struct ERTexture {
    char pad[24];
    void* operator new(size_t);
    ERTexture();
    static ERTexture* New();
};

ERTexture* ERTexture::New() {
    return new ERTexture();
}
