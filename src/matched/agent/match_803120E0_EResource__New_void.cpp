typedef unsigned int size_t;

struct EResource {
    char pad[20];
    void* operator new(size_t);
    EResource();
    static EResource* New();
};

EResource* EResource::New() {
    return new EResource();
}
