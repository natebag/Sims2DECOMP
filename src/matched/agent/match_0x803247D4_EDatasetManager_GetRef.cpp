// 0x803247D4 (60B) EDatasetManager::GetRef(char*)
// Two-call pattern: this->GetRefByHash(HashName(name))

extern int HashName(char*);

class EDatasetManager {
public:
    void* GetRef(char*);
    void* GetRefByHash(int hash);
};

void* EDatasetManager::GetRef(char* name) {
    return GetRefByHash(HashName(name));
}
