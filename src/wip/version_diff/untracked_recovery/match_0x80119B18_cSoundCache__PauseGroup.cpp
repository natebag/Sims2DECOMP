class cTrack {
public:
    void* m_info;
    
    int GetControlGroup();
    void Pause();
};

class cSoundCache {
public:
    cTrack* m_tracks[64];
    
    void PauseGroup(int group);
};

void cSoundCache::PauseGroup(int group) {
    char* base = (char*)this;
    for (int i = 0; i < 64; i++) {
        cTrack* track = *(cTrack**)(base + i * 4);
        if (track) {
            if (group == -1) {
                track->Pause();
            } else if (track->m_info) {
                if (track->GetControlGroup() == group) {
                    track->Pause();
                }
            }
        }
    }
}
