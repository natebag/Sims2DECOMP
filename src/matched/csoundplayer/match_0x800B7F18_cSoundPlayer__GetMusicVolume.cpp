/* cSoundPlayer::GetMusicVolume(void) - 0x800B7F18 (20 bytes) */

extern char g_cSoundPlayer[100];

class cSoundPlayer {
public:
    char pad[29];
    signed char m_vol;

    static signed char GetMusicVolume(void);
};

signed char cSoundPlayer::GetMusicVolume(void) {
    cSoundPlayer* self = *(cSoundPlayer**)g_cSoundPlayer;
    return self->m_vol;
}
