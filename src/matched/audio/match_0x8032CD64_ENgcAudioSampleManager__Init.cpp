// 0x8032CD64 ENgcAudioSampleManager::Init(char *) (60B)

class EResourceManager {
public:
    void Init(char* name);
};

class ENgcAudioSampleManager : public EResourceManager {
    void heapInit();
public:
    void Init(char* name);
};

void ENgcAudioSampleManager::Init(char* name) {
    heapInit();
    EResourceManager::Init(name);
}
