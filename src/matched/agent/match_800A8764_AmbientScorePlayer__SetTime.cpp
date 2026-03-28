// 0x800A8764 (8 bytes)
class AmbientScorePlayer {
public:
    char pad[52];
    float m_time;

    void SetTime(float t);
};

void AmbientScorePlayer::SetTime(float t) {
    m_time = t;
}
