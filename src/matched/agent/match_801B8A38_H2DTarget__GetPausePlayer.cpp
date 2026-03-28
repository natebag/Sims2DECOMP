class H2DTarget {
public:
    char _pad[0xD0];
    int m_pausePlayer;

    int GetPausePlayer();
};

int H2DTarget::GetPausePlayer() {
    return m_pausePlayer;
}
