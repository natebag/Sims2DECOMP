// 0x800B7F40 cSoundPlayer::GetAmbientVolume(void) (20B)
struct SndVolumeState {
    char _pad[0x29];
    signed char m_ambientVolume;
};
extern char g_sndVolumeMgr[16];
struct cSoundPlayer {
    int GetAmbientVolume() const;
};
int cSoundPlayer::GetAmbientVolume() const {
    SndVolumeState* state = *(SndVolumeState**)g_sndVolumeMgr;
    return state->m_ambientVolume;
}
