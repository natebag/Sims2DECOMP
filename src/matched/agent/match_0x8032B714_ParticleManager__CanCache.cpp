struct EResource;
struct ParticleManager {
    int CanCache(EResource *);
};
int ParticleManager::CanCache(EResource *) { return 1; }
