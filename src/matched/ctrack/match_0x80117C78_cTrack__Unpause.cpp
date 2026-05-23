// 0x80117C78 cTrack::Unpause() (100B)

class cSampleChannel {
public:
    int Unpause();
};

class cHitMan {
public:
    char pad[0x14];
    int m_14;
    void AddToUpdateList(class cTrack* t);
};

extern cHitMan* g_hitman;

class cTrack {
public:
    char pad[0x18];
    int m_18;
    char pad1C[0x18];
    void* m_34;
    int m_38;
    char pad3C[0x14];
    cSampleChannel* m_50;
    int Unpause();
};

int cTrack::Unpause() {
    m_38 = 0;
    if (m_34 != 0) {
        cSampleChannel* sc = m_50;
        if (sc != 0) {
            sc->Unpause();
        }
        cHitMan* hm = g_hitman;
        m_18 = hm->m_14;
        hm->AddToUpdateList(this);
    }
    return 1;
}
