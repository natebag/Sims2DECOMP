// 0x80118E40 (12 bytes)
// cTrack::GetControlGroup(void)
// lwz r9, 0(r3); lbz r3, 23(r9); blr
struct cTrackData {
    char m_pad[23];
    unsigned char m_controlGroup;
};

class cTrack {
public:
    cTrackData* m_data;
    unsigned char GetControlGroup();
};

unsigned char cTrack::GetControlGroup() {
    return m_data->m_controlGroup;
}
