// 0x8032CAA0 ENgcAudio::SetSpeakerVolumes(EVoice *, int *, unsigned int) (108B)

extern int gv_audioEnabled;

class ENgcSFXStreamer {
public:
    void SetLeftVolume(unsigned int id, int vol);
    void SetRightVolume(unsigned int id, int vol);
};

extern ENgcSFXStreamer* gv_sfxStreamer;

class EVoice {
public:
    char _pad0[8];
    unsigned int m_id;
    char _pad12[16];
    int m_field28;
};

class ENgcAudio {
public:
    void SetSpeakerVolumes(EVoice* voice, int* vols, unsigned int n);
};

void ENgcAudio::SetSpeakerVolumes(EVoice* voice, int* vols, unsigned int /*n*/) {
    if (gv_audioEnabled == 0) return;
    if (voice == 0) return;
    if (voice->m_field28 != 0) return;
    gv_sfxStreamer->SetLeftVolume(voice->m_id, vols[0]);
    gv_sfxStreamer->SetRightVolume(voice->m_id, vols[1]);
}
