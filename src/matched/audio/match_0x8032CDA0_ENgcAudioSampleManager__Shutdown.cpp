// 0x8032CDA0 ENgcAudioSampleManager::Shutdown(void) (32B)

class EResourceManager {
public:
    void Shutdown();
};

class ENgcAudioSampleManager : public EResourceManager {
public:
    void Shutdown();
};

void ENgcAudioSampleManager::Shutdown() {
    EResourceManager::Shutdown();
}
