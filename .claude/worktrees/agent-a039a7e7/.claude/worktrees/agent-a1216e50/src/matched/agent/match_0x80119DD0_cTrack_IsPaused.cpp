/* cTrack::IsPaused(void) - 0x80119DD0 - 24 bytes */
/* lwz r0, 0x38(r3); li r3, 1; cmpwi r0, 0; bnelr; li r3, 0; blr */

class cTrack {
public:
    char _pad[0x38];
    int m_pauseCount;

    int IsPaused(void);
};

int cTrack::IsPaused(void) {
    return m_pauseCount != 0;
}
