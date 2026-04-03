struct EResource;
struct EAudioSampleManager {
    int CanCache(EResource *);
};
int EAudioSampleManager::CanCache(EResource *) { return 1; }
