/* AmbientScorePlayer::SetVolume(int) at 0x800A8B10 (12B) */

struct AmbientScorePlayer {
    char pad[0x14];
    int m_volume;

    int SetVolume(int vol);
};

int AmbientScorePlayer::SetVolume(int vol) {
    m_volume = vol;
    return 1;
}
