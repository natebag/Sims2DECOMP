/* EBinaryManager::AddRef(char*, EFile*, int) at 0x803231AC (32B) */
// 0x803231AC (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(char*, EFile*, int);
};
class EBinaryManager : public EResourceManager {
public:
    void AddRef(char* name, EFile* file, int flag);
};
void EBinaryManager::AddRef(char* name, EFile* file, int flag) {
    EResourceManager::AddRef(name, file, flag);
}
