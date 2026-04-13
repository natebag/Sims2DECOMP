// 0x800A88E0 AmbientScorePlayer::Start (60b)

extern int timeGetTime(void);

struct AmbientScorePlayer {
    int m_state;
    char pad[0x34];
    int m_startTime;
    int Start();
};

int AmbientScorePlayer::Start() {
    this->m_startTime = timeGetTime();
    this->m_state = 1;
    return 1;
}
