struct EResource;
struct EModelManager {
    int CanCache(EResource *);
};
int EModelManager::CanCache(EResource *) { return 1; }
