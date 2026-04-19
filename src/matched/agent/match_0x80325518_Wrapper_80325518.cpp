/* EQuickdataManager::AddRef(char*, EFile*, int) at 0x80325518 (32B) */
// 0x80325518 (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(char*, EFile*, int);
};
class EQuickdataManager : public EResourceManager {
public:
    void AddRef(char* name, EFile* file, int flag);
};
void EQuickdataManager::AddRef(char* name, EFile* file, int flag) {
    EResourceManager::AddRef(name, file, flag);
}
