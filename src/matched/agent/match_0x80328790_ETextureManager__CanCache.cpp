struct EResource;
struct ETextureManager {
    int CanCache(EResource *);
};
int ETextureManager::CanCache(EResource *) { return 1; }
