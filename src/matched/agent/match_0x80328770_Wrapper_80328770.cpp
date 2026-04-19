/* ETextureManager::AddRef(char*, EFile*, int) at 0x80328770 (32B) */
// 0x80328770 (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(char*, EFile*, int);
};
class ETextureManager : public EResourceManager {
public:
    void AddRef(char* name, EFile* file, int flag);
};
void ETextureManager::AddRef(char* name, EFile* file, int flag) {
    EResourceManager::AddRef(name, file, flag);
}
