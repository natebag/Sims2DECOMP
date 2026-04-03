struct EResource;
struct EFlashManager {
    int CanCache(EResource *);
};
int EFlashManager::CanCache(EResource *) { return 1; }
