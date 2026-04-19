/* EModelManager::AddRef(unsigned int, EFile*, int) at 0x80324FB8 (32B) */
// 0x80324FB8 (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(unsigned int, EFile*, int);
};
class EModelManager : public EResourceManager {
public:
    void AddRef(unsigned int id, EFile* file, int flag);
};
void EModelManager::AddRef(unsigned int id, EFile* file, int flag) {
    EResourceManager::AddRef(id, file, flag);
}
