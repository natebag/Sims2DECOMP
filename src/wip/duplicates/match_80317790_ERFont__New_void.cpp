typedef unsigned int size_t;

struct ERFont {
    char pad[108];
    void* operator new(size_t);
    ERFont();
    static ERFont* New();
};

ERFont* ERFont::New() {
    return new ERFont();
}
