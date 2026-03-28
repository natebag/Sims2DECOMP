/* AmbientScorePlayer::GetTime(void) at 0x800A876C (8B) */

struct AmbientScorePlayer {
    char pad[0x34];
    float m_time;

    float GetTime(void);
};

float AmbientScorePlayer::GetTime(void) {
    return m_time;
}
