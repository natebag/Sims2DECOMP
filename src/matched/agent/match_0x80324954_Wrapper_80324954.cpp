/* EDatasetManager::AddRef(unsigned int, EFile*, int) at 0x80324954 (32B) */
// 0x80324954 (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(unsigned int, EFile*, int);
};
class EDatasetManager : public EResourceManager {
public:
    void AddRef(unsigned int id, EFile* file, int flag);
};
void EDatasetManager::AddRef(unsigned int id, EFile* file, int flag) {
    EResourceManager::AddRef(id, file, flag);
}
