// 0x80118E28 (12 bytes)
// cTrack::GetMinRange(void)
// lwz r9, 0(r3); lbz r3, 31(r9); blr
struct cTrackData {
    char m_pad[31];
    unsigned char m_minRange;
};

class cTrack {
public:
    cTrackData* m_data;
    unsigned char GetMinRange();
};

unsigned char cTrack::GetMinRange() {
    return m_data->m_minRange;
}
