// 0x8032CCF0 ENgcAudioSampleManager::ENgcAudioSampleManager(void) (68B)

struct _EAudioSampleManagerBase {
    char _pre[0x54];
    int m_cacheEnabled;
    char _post[0xCC4];
};

class EAudioSampleManager : public _EAudioSampleManagerBase {
public:
    EAudioSampleManager();
    virtual ~EAudioSampleManager();
};

class ENgcAudioSampleManager : public EAudioSampleManager {
public:
    ENgcAudioSampleManager();
};

ENgcAudioSampleManager::ENgcAudioSampleManager() : EAudioSampleManager() {
    m_cacheEnabled = 1;
}
