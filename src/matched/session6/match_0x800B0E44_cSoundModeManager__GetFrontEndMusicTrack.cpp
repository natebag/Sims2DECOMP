// cSoundModeManager::GetFrontEndMusicTrack(bool)
// Address: 0x800B0E44 | Size: 44 bytes

struct cSoundModeManager {
    char pad[40];
    int field_40;
    int GetFrontEndMusicTrack(bool arg);
};

extern int g_frontEndMusicTracks[];

int cSoundModeManager::GetFrontEndMusicTrack(bool arg) {
    if (arg) {
        return g_frontEndMusicTracks[this->field_40];
    }
    return g_frontEndMusicTracks[0];
}
