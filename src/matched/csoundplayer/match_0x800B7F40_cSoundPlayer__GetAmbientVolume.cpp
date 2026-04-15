/* cSoundPlayer::GetAmbientVolume(void) - 0x800B7F40 (20 bytes) */

extern char g_cSoundPlayer[100];

class cSoundPlayer {
public:
    char pad[41];
    signed char m_vol;

    static signed char GetAmbientVolume(void);
};

signed char cSoundPlayer::GetAmbientVolume(void) {
    cSoundPlayer* self = *(cSoundPlayer**)g_cSoundPlayer;
    return self->m_vol;
}
