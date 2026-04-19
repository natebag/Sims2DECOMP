/* EAudioSampleManager::AddRef(unsigned int, EFile*, int) at 0x8032D94C (32B) */
// 0x8032D94C (32 bytes)

class EFile;
class EResourceManager {
public:
    void AddRef(unsigned int, EFile*, int);
};
class EAudioSampleManager : public EResourceManager {
public:
    void AddRef(unsigned int id, EFile* file, int flag);
};

void EAudioSampleManager::AddRef(unsigned int id, EFile* file, int flag) {
    EResourceManager::AddRef(id, file, flag);
}
