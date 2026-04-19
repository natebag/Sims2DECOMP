/* EAnimManager::AddRef(char*, EFile*, int) at 0x80322E28 (32B) */
// 0x80322E28 (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(char*, EFile*, int);
};
class EAnimManager : public EResourceManager {
public:
    void AddRef(char* name, EFile* file, int flag);
};
void EAnimManager::AddRef(char* name, EFile* file, int flag) {
    EResourceManager::AddRef(name, file, flag);
}
