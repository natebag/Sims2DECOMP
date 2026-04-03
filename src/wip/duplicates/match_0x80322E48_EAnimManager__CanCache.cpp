struct EResource;
struct EAnimManager {
    int CanCache(EResource *);
};
int EAnimManager::CanCache(EResource *) { return 1; }
