/* cTrack::GetControlGroup(void) - 0x80118E40 - 12 bytes */

struct ERSoundTrackData {
    char _pad[0x17];
    unsigned char m_controlGroup;
};

class cTrack {
public:
    ERSoundTrackData* m_data;
    int GetControlGroup(void);
};

int cTrack::GetControlGroup(void) {
    return m_data->m_controlGroup;
}
