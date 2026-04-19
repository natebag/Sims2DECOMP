/* ECharacterManager::AddRef(unsigned int, EFile*, int) at 0x803232FC (32B) */
// 0x803232FC (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(unsigned int, EFile*, int);
};
class ECharacterManager : public EResourceManager {
public:
    void AddRef(unsigned int id, EFile* file, int flag);
};
void ECharacterManager::AddRef(unsigned int id, EFile* file, int flag) {
    EResourceManager::AddRef(id, file, flag);
}
