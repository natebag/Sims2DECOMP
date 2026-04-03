struct EResource;
struct EAmbientScoreManager {
    int CanCache(EResource *);
};
int EAmbientScoreManager::CanCache(EResource *) { return 1; }
