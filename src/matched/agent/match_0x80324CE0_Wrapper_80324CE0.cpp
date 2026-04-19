/* EFlashManager::AddRef(char*, EFile*, int) at 0x80324CE0 (32B) */
// 0x80324CE0 (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(char*, EFile*, int);
};
class EFlashManager : public EResourceManager {
public:
    void AddRef(char* name, EFile* file, int flag);
};
void EFlashManager::AddRef(char* name, EFile* file, int flag) {
    EResourceManager::AddRef(name, file, flag);
}
