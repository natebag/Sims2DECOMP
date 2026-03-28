struct EResource;
struct EDatasetManager {
    int CanCache(EResource *);
};
int EDatasetManager::CanCache(EResource *) { return 1; }
