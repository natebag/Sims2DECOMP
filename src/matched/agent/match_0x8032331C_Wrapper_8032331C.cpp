/* ECharacterManager::AddRef(char*, EFile*, int) at 0x8032331C (32B) */
// 0x8032331C (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(char*, EFile*, int);
};
class ECharacterManager : public EResourceManager {
public:
    void AddRef(char* name, EFile* file, int flag);
};
void ECharacterManager::AddRef(char* name, EFile* file, int flag) {
    EResourceManager::AddRef(name, file, flag);
}
