// 0x80118E34 (12 bytes)
// cTrack::GetMaxRange(void)
// lwz r9, 0(r3); lbz r3, 32(r9); blr
struct cTrackData {
    char m_pad[32];
    unsigned char m_maxRange;
};

class cTrack {
public:
    cTrackData* m_data;
    unsigned char GetMaxRange();
};

unsigned char cTrack::GetMaxRange() {
    return m_data->m_maxRange;
}
