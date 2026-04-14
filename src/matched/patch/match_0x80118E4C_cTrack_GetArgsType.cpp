/* cTrack::GetArgsType(void) - 0x80118E4C - 12 bytes */

struct ERSoundTrackData {
    char _pad[0x15];
    unsigned char m_argsType;
};

class cTrack {
public:
    ERSoundTrackData* m_data;
    int GetArgsType(void);
};

int cTrack::GetArgsType(void) {
    return m_data->m_argsType;
}
