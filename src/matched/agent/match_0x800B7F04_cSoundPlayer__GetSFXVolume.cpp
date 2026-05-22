// 0x800B7F04 cSoundPlayer::GetSFXVolume(void) (20B)
// Non-SDA global pointer: extern char[] forces non-SDA lis+lwz via compiler folding.

struct SndVolumeState {
    char _pad[0x1c];
    signed char m_sfxVolume;
};

extern char g_sndVolumeMgr[16];

struct cSoundPlayer {
    int GetSFXVolume() const;
};

int cSoundPlayer::GetSFXVolume() const {
    SndVolumeState* state = *(SndVolumeState**)g_sndVolumeMgr;
    return state->m_sfxVolume;
}
