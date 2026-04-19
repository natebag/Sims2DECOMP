/* EAmbientScoreManager::AddRef(unsigned int, EFile*, int) at 0x80322C84 (32B) */
// 0x80322C84 (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(unsigned int, EFile*, int);
};
class EAmbientScoreManager : public EResourceManager {
public:
    void AddRef(unsigned int id, EFile* file, int flag);
};
void EAmbientScoreManager::AddRef(unsigned int id, EFile* file, int flag) {
    EResourceManager::AddRef(id, file, flag);
}
