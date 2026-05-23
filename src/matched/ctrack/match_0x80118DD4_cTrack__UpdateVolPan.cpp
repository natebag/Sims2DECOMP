// 0x80118DD4 cTrack::UpdateVolPan() (84B)

class cSampleChannel {
public:
    void SetVolume(int v);
    void SetPan(int p);
};

class cTrack {
public:
    char pad[0x50];
    cSampleChannel* m_50;
    char pad54[0x24];
    int m_78;
    int CalculateCurrentVolume();
    int UpdateVolPan();
};

int cTrack::UpdateVolPan() {
    cSampleChannel* sub = m_50;
    if (sub != 0) {
        int v = CalculateCurrentVolume();
        sub->SetVolume(v);
        m_50->SetPan(m_78);
    }
    return 1;
}
