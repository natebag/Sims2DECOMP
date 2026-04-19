/* EAudioStreamManager::AddRef(char*, EFile*, int) at 0x80322FE8 (32B) */
// 0x80322FE8 (32 bytes)

class EFile;
class EResourceManager {
public:
    void AddRef(char*, EFile*, int);
};
class EAudioStreamManager : public EResourceManager {
public:
    void AddRef(char* name, EFile* file, int flag);
};

void EAudioStreamManager::AddRef(char* name, EFile* file, int flag) {
    EResourceManager::AddRef(name, file, flag);
}
