/* EAmbientScoreManager::AddRef(char*, EFile*, int) at 0x80322CA4 (32B) */
// 0x80322CA4 (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(char*, EFile*, int);
};
class EAmbientScoreManager : public EResourceManager {
public:
    void AddRef(char* name, EFile* file, int flag);
};
void EAmbientScoreManager::AddRef(char* name, EFile* file, int flag) {
    EResourceManager::AddRef(name, file, flag);
}
