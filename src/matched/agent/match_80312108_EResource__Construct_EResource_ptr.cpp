typedef unsigned int size_t;
void* operator new(size_t, void*);

struct EResource {
    char pad[20];
    EResource();
    static void Construct(EResource* obj);
};

void EResource::Construct(EResource* obj) {
    new (obj) EResource();
}
