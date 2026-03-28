// 0x800A876C (8 bytes)
class AmbientScorePlayer {
public:
    char pad[52];
    float m_time;

    float GetTime(void);
};

float AmbientScorePlayer::GetTime(void) {
    return m_time;
}
