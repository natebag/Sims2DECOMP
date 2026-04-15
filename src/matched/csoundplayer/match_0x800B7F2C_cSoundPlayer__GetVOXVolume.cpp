/* cSoundPlayer::GetVOXVolume(void) - 0x800B7F2C (20 bytes) */

extern char g_cSoundPlayer[100];

class cSoundPlayer {
public:
    char pad[40];
    signed char m_vol;

    static signed char GetVOXVolume(void);
};

signed char cSoundPlayer::GetVOXVolume(void) {
    cSoundPlayer* self = *(cSoundPlayer**)g_cSoundPlayer;
    return self->m_vol;
}
