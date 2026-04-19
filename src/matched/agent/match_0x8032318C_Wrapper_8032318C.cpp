/* EBinaryManager::AddRef(unsigned int, EFile*, int) at 0x8032318C (32B) */
// 0x8032318C (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(unsigned int, EFile*, int);
};
class EBinaryManager : public EResourceManager {
public:
    void AddRef(unsigned int id, EFile* file, int flag);
};
void EBinaryManager::AddRef(unsigned int id, EFile* file, int flag) {
    EResourceManager::AddRef(id, file, flag);
}
