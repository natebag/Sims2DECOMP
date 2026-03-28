/* cSampleChannel::Snd(int) - 0x80119278 - 12 bytes */

struct cSampleChannelData {
    char _pad[0x18];
    int m_snd;
};

class cSampleChannel {
public:
    cSampleChannelData* m_data;
    int Snd(int);
};

int cSampleChannel::Snd(int) {
    return m_data->m_snd;
}
