// 0x800B7F18 cSoundPlayer::GetMusicVolume(void) (20B)
struct SndVolumeState {
    char _pad[0x1d];
    signed char m_musicVolume;
};
extern char g_sndVolumeMgr[16];
struct cSoundPlayer {
    int GetMusicVolume() const;
};
int cSoundPlayer::GetMusicVolume() const {
    SndVolumeState* state = *(SndVolumeState**)g_sndVolumeMgr;
    return state->m_musicVolume;
}
