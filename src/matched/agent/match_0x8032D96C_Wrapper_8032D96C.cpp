/* EAudioSampleManager::AddRef(char*, EFile*, int) at 0x8032D96C (32B) */
// 0x8032D96C (32 bytes)

class EFile;
class EResourceManager {
public:
    void AddRef(char*, EFile*, int);
};
class EAudioSampleManager : public EResourceManager {
public:
    void AddRef(char* name, EFile* file, int flag);
};

void EAudioSampleManager::AddRef(char* name, EFile* file, int flag) {
    EResourceManager::AddRef(name, file, flag);
}
