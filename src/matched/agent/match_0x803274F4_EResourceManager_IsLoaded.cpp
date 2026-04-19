// 0x803274F4 (60B) EResourceManager::IsLoaded(char*)
// Two-call pattern: this->IsLoadedByHash(HashName(name))

extern int HashNameIL(char*);

class EResourceManagerIL {
public:
    void* IsLoaded(char*);
    void* IsLoadedByHash(int hash);
};

void* EResourceManagerIL::IsLoaded(char* name) {
    return IsLoadedByHash(HashNameIL(name));
}
