// 0x80119DD0 cTrack::IsPaused(void) (24B)
struct cTrack_Ip {
    char _pad[0x38];
    int m_isPaused;
    int IsPaused() const;
};
int cTrack_Ip::IsPaused() const {
    if (m_isPaused) return 1;
    return 0;
}
