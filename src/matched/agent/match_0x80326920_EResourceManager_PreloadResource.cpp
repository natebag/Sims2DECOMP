// 0x80326920 (60B) EResourceManager::PreloadResource(char*)
// Two-call pattern: this->PreloadByHash(HashName(name))

extern int HashNamePre(char*);

class EResourceManagerPre {
public:
    void* PreloadResource(char*);
    void* PreloadByHash(int hash);
};

void* EResourceManagerPre::PreloadResource(char* name) {
    return PreloadByHash(HashNamePre(name));
}
