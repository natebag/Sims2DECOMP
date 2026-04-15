/* cSoundPlayer::GetSFXVolume(void) - 0x800B7F04 (20 bytes) */

extern char g_cSoundPlayer[100];

class cSoundPlayer {
public:
    char pad[28];
    signed char m_vol;

    static signed char GetSFXVolume(void);
};

signed char cSoundPlayer::GetSFXVolume(void) {
    cSoundPlayer* self = *(cSoundPlayer**)g_cSoundPlayer;
    return self->m_vol;
}
