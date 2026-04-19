/* EShaderManager::AddRef(unsigned int, EFile*, int) at 0x803282D4 (32B) */
// 0x803282D4 (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(unsigned int, EFile*, int);
};
class EShaderManager : public EResourceManager {
public:
    void AddRef(unsigned int id, EFile* file, int flag);
};
void EShaderManager::AddRef(unsigned int id, EFile* file, int flag) {
    EResourceManager::AddRef(id, file, flag);
}
