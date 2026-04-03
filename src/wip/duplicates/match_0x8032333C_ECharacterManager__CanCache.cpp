struct EResource;
struct ECharacterManager {
    int CanCache(EResource *);
};
int ECharacterManager::CanCache(EResource *) { return 1; }
