/* EAudioStreamManager::AddRef(unsigned int, EFile*, int) at 0x80322FC8 (32B) */
// 0x80322FC8 (32 bytes)

class EFile;
class EResourceManager {
public:
    void AddRef(unsigned int, EFile*, int);
};
class EAudioStreamManager : public EResourceManager {
public:
    void AddRef(unsigned int id, EFile* file, int flag);
};

void EAudioStreamManager::AddRef(unsigned int id, EFile* file, int flag) {
    EResourceManager::AddRef(id, file, flag);
}
