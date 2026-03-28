struct EResource;
struct ESoundEventManager {
    int CanCache(EResource *);
};
int ESoundEventManager::CanCache(EResource *) { return 1; }
