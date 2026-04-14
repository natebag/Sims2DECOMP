/* cTrack::GetMaxRange(void) - 0x80118E34 - 12 bytes */

struct ERSoundTrackData {
    char _pad[0x20];
    unsigned char m_maxRange;
};

class cTrack {
public:
    ERSoundTrackData* m_data;
    int GetMaxRange(void);
};

int cTrack::GetMaxRange(void) {
    return m_data->m_maxRange;
}
