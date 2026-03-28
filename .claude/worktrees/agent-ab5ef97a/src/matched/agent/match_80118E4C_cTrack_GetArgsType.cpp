// 0x80118E4C (12 bytes)
// cTrack::GetArgsType(void)
// lwz r9, 0(r3); lbz r3, 21(r9); blr
struct cTrackData {
    char m_pad[21];
    unsigned char m_argsType;
};

class cTrack {
public:
    cTrackData* m_data;
    unsigned char GetArgsType();
};

unsigned char cTrack::GetArgsType() {
    return m_data->m_argsType;
}
