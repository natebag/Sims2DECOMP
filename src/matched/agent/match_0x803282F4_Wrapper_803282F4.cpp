/* EShaderManager::AddRef(char*, EFile*, int) at 0x803282F4 (32B) */
// 0x803282F4 (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(char*, EFile*, int);
};
class EShaderManager : public EResourceManager {
public:
    void AddRef(char* name, EFile* file, int flag);
};
void EShaderManager::AddRef(char* name, EFile* file, int flag) {
    EResourceManager::AddRef(name, file, flag);
}
