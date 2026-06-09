/* AmbientScorePlayer::SetTime(float) at 0x800A8764 (8B) */

struct AmbientScorePlayer {
    char pad[0x34];
    float m_time;

    void SetTime(float t);
};

void AmbientScorePlayer::SetTime(float t) {
    m_time = t;
}
