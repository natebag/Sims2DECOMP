struct EResource;
struct ESoundTrackDataManager {
    int CanCache(EResource *);
};
int ESoundTrackDataManager::CanCache(EResource *) { return 1; }
