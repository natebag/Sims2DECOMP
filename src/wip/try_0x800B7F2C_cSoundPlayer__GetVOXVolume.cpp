// 0x800B7F2C cSoundPlayer::GetVOXVolume(void) (20B)
struct SndVolumeState {
    char _pad[0x28];
    signed char m_voxVolume;
};
extern char g_sndVolumeMgr[16];
struct cSoundPlayer {
    int GetVOXVolume() const;
};
int cSoundPlayer::GetVOXVolume() const {
    SndVolumeState* state = *(SndVolumeState**)g_sndVolumeMgr;
    return state->m_voxVolume;
}
