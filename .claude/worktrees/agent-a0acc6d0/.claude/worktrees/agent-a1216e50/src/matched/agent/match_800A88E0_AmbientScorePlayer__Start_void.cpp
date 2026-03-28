typedef unsigned long u32;

extern "C" u32 timeGetTime(void);

class AmbientScorePlayer {
public:
    int m_state;
    int pad_004;
    void* m_ambientScore;
    int pad_00C;
    int m_numPlaying;
    int m_volume;
    int pad_018;
    int m_numListeners;
    char pad_020[0x18];
    u32 m_startTimestamp;

    int Start(void);
};

int AmbientScorePlayer::Start(void)
{
    m_startTimestamp = timeGetTime();
    m_state = 1;
    return 1;
}
