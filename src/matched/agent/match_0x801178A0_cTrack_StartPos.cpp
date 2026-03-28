/* cTrack::StartPos(void) - 0x801178A0 - 12 bytes */
/* lwz r9, 0(r3); lwz r3, 48(r9); blr */

struct cTrackData {
    char _pad[0x30];
    int m_startPos;
};

class cTrack {
public:
    cTrackData* m_data;

    int StartPos(void);
};

int cTrack::StartPos(void) {
    return m_data->m_startPos;
}
