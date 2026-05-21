// 0x8032CD34 ENgcAudioSampleManager::~ENgcAudioSampleManager(void) (48B)

struct _EAudioSampleManagerBase { char _[0xD1C]; };

class EAudioSampleManager : public _EAudioSampleManagerBase {
public:
    virtual ~EAudioSampleManager();
};

class ENgcAudioSampleManager : public EAudioSampleManager {
public:
    ~ENgcAudioSampleManager();
};

ENgcAudioSampleManager::~ENgcAudioSampleManager() {}
