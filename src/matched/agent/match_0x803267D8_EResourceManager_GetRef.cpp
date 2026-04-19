// 0x803267D8 (60B) EResourceManager::GetRef(char*)
// Two-call pattern: this->GetRefByHash(HashName(name))

extern int HashName2(char*);

class EResourceManagerGR {
public:
    void* GetRef(char*);
    void* GetRefByHash2(int hash);
};

void* EResourceManagerGR::GetRef(char* name) {
    return GetRefByHash2(HashName2(name));
}
