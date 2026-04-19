/* ENgcAudioSampleManager::Shutdown(void) at 0x8032CDA0 (32B) */
// 0x8032CDA0 (32 bytes)

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
