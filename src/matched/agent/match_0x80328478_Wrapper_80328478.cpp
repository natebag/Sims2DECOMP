/* ESoundEventManager::AddRef(char*, EFile*, int) at 0x80328478 (32B) */
// 0x80328478 (32 bytes)

class EFile;
class EResourceManager {
public:
    void AddRef(char*, EFile*, int);
};
class ESoundEventManager : public EResourceManager {
public:
    void AddRef(char* name, EFile* file, int flag);
};

void ESoundEventManager::AddRef(char* name, EFile* file, int flag) {
    EResourceManager::AddRef(name, file, flag);
}
