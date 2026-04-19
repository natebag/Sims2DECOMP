/* EQuickdataManager::AddRef(unsigned int, EFile*, int) at 0x803254F8 (32B) */
// 0x803254F8 (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(unsigned int, EFile*, int);
};
class EQuickdataManager : public EResourceManager {
public:
    void AddRef(unsigned int id, EFile* file, int flag);
};
void EQuickdataManager::AddRef(unsigned int id, EFile* file, int flag) {
    EResourceManager::AddRef(id, file, flag);
}
