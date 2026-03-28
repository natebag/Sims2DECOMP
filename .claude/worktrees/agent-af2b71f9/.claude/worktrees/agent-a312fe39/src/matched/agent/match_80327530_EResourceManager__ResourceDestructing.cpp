// 0x80327530 (4 bytes)
class EResource;
class EResourceManager {
public:
    void ResourceDestructing(EResource*);
};
void EResourceManager::ResourceDestructing(EResource*) {}
