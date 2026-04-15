// 0x803245F0 EDatasetManager::AddRef(EResource*) (48B)
// Skip if null or == 1, else forward to helper

struct EResource;
struct EDatasetManager {
    void AddRef(EResource* r);
    void AddRefImpl(EResource* r);
};

void EDatasetManager::AddRef(EResource* r) {
    if (r == 0) return;
    if (r == (EResource*)1) return;
    AddRefImpl(r);
}
