// 0x80119DC8 cTrack::IsPlaying(void) (8B)
struct cTrack_IP {
    char _pad[0x34];
    int m_isPlaying;
    int IsPlaying() const;
};
int cTrack_IP::IsPlaying() const { return m_isPlaying; }
