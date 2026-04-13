// 0x800B0EF0 cSoundModeManager::GetDemoMusicTrack (24B)
extern char gMusicTrackTable[];
struct cSoundModeManager {
    char pad[0x2C];
    int m_trackIndex;
};
void* cSoundModeManager_GetDemoMusicTrack(cSoundModeManager* self) {
    return ((void**)gMusicTrackTable)[self->m_trackIndex];
}
