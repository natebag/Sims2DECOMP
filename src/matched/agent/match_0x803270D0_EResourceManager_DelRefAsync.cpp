// 0x803270D0 (60B) EResourceManager::DelRefAsync(char*)
// Two-call pattern: this->DelRefAsyncByHash(HashName(name))

extern int HashNameDR(char*);

class EResourceManagerDR {
public:
    void* DelRefAsync(char*);
    void* DelRefAsyncByHash(int hash);
};

void* EResourceManagerDR::DelRefAsync(char* name) {
    return DelRefAsyncByHash(HashNameDR(name));
}
