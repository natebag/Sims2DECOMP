class AmbientScorePlayer {
public:
    int m_state;

    int Stop(void);
    int KillAllAmbientSounds(void);
};

int AmbientScorePlayer::Stop(void)
{
    int result;

    m_state = 0;
    result = KillAllAmbientSounds();
    if (result == 0) {
        return 0;
    }
    return 1;
}
