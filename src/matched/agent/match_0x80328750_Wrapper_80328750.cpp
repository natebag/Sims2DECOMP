/* ETextureManager::AddRef(unsigned int, EFile*, int) at 0x80328750 (32B) */
// 0x80328750 (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(unsigned int, EFile*, int);
};
class ETextureManager : public EResourceManager {
public:
    void AddRef(unsigned int id, EFile* file, int flag);
};
void ETextureManager::AddRef(unsigned int id, EFile* file, int flag) {
    EResourceManager::AddRef(id, file, flag);
}
