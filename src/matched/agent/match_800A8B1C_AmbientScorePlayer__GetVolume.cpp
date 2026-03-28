// 0x800A8B1C (8 bytes)
class AmbientScorePlayer {
public:
    char pad[20];
    int m_volume;

    int GetVolume(void);
};

int AmbientScorePlayer::GetVolume(void) {
    return m_volume;
}
