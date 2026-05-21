// 0x8032CFDC ENgcAudioSampleManager::OnDelRef(ERSampledata *) (68B)

extern unsigned int AramHeapBegin;

struct ERSampledata {
    char pad[28];
    unsigned int m_aramOffset;
};

class ENgcAudioSampleManager {
    void heapFree(unsigned int offset);
public:
    void OnDelRef(ERSampledata* sample);
};

void ENgcAudioSampleManager::OnDelRef(ERSampledata* sample) {
    if (sample->m_aramOffset >= AramHeapBegin) {
        heapFree(sample->m_aramOffset);
        sample->m_aramOffset = 0;
    }
}
