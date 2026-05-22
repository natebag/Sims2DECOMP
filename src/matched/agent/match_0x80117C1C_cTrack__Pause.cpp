// 0x80117C1C cTrack::Pause() (92B)

class cSampleChannel {
public:
    int Pause();
};

class cHitMan {
public:
    void RemoveFromUpdateList(class cTrack* t);
};

extern cHitMan* g_hitman;  // SDA at -0x5E48

class cTrack {
public:
    char pad[0x34];
    void* m_34;
    int m_38;
    char pad3C[0x14];
    cSampleChannel* m_50;
    int Pause();
};

int cTrack::Pause() {
    m_38 = 1;
    if (m_34 != 0) {
        cSampleChannel* sc = m_50;
        if (sc != 0) {
            sc->Pause();
        }
        g_hitman->RemoveFromUpdateList(this);
    }
    return 1;
}
