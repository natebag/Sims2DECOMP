struct EResource;
struct EffectsAttachmentManager {
    int CanCache(EResource *);
};
int EffectsAttachmentManager::CanCache(EResource *) { return 1; }
