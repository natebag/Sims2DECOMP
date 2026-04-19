// 0x80326F24 (60B) EResourceManager::Refresh(char*)
// Two-call pattern: this->RefreshByHash(HashName(name))

extern int HashName(char*);

class EResourceManager {
public:
    void* Refresh(char*);
    void* RefreshByHash(int hash);
};

void* EResourceManager::Refresh(char* name) {
    return RefreshByHash(HashName(name));
}
