/* cTrack::GetMinRange(void) - 0x80118E28 - 12 bytes */

struct ERSoundTrackData {
    char _pad[0x1F];
    unsigned char m_minRange;
};

class cTrack {
public:
    ERSoundTrackData* m_data;
    int GetMinRange(void);
};

int cTrack::GetMinRange(void) {
    return m_data->m_minRange;
}
