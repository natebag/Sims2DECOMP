typedef unsigned int size_t;
void* operator new(size_t, void*);

struct ERFont {
    char pad[108];
    ERFont();
    static void Construct(ERFont* obj);
};

void ERFont::Construct(ERFont* obj) {
    new (obj) ERFont();
}
