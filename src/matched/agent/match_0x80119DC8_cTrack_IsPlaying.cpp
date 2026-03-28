/* cTrack::IsPlaying(void) - 0x80119DC8 - 8 bytes */
/* lwz r3, 52(r3); blr */

class cTrack {
public:
    char _pad[0x34];
    int m_isPlaying;

    int IsPlaying(void);
};

int cTrack::IsPlaying(void) {
    return m_isPlaying;
}
