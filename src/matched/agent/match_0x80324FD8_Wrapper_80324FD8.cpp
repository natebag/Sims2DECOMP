/* EModelManager::AddRef(char*, EFile*, int) at 0x80324FD8 (32B) */
// 0x80324FD8 (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(char*, EFile*, int);
};
class EModelManager : public EResourceManager {
public:
    void AddRef(char* name, EFile* file, int flag);
};
void EModelManager::AddRef(char* name, EFile* file, int flag) {
    EResourceManager::AddRef(name, file, flag);
}
