struct EResource;
struct EQuickdataManager {
    int CanCache(EResource *);
};
int EQuickdataManager::CanCache(EResource *) { return 1; }
