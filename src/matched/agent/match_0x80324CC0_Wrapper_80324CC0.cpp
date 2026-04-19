/* EFlashManager::AddRef(unsigned int, EFile*, int) at 0x80324CC0 (32B) */
// 0x80324CC0 (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(unsigned int, EFile*, int);
};
class EFlashManager : public EResourceManager {
public:
    void AddRef(unsigned int id, EFile* file, int flag);
};
void EFlashManager::AddRef(unsigned int id, EFile* file, int flag) {
    EResourceManager::AddRef(id, file, flag);
}
