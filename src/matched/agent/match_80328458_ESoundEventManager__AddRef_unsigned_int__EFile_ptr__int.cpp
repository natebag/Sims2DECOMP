/* ESoundEventManager::AddRef(unsigned int, EFile*, int) at 0x80328458 (32B) */
// 0x80328458 (32 bytes)

class EFile;
class EResourceManager {
public:
    void AddRef(unsigned int, EFile*, int);
};
class ESoundEventManager : public EResourceManager {
public:
    void AddRef(unsigned int id, EFile* file, int flag);
};

void ESoundEventManager::AddRef(unsigned int id, EFile* file, int flag) {
    EResourceManager::AddRef(id, file, flag);
}
