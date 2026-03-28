struct EResource;
struct EShaderManager {
    int CanCache(EResource *);
};
int EShaderManager::CanCache(EResource *) { return 1; }
