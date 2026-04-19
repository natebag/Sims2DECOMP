/* EAnimManager::AddRef(unsigned int, EFile*, int) at 0x80322E08 (32B) */
// 0x80322E08 (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(unsigned int, EFile*, int);
};
class EAnimManager : public EResourceManager {
public:
    void AddRef(unsigned int id, EFile* file, int flag);
};
void EAnimManager::AddRef(unsigned int id, EFile* file, int flag) {
    EResourceManager::AddRef(id, file, flag);
}
