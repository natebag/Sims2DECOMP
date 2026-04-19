/* ParticleManager::AddRef(char*, EFile*, int) at 0x8032B6F4 (32B) */
// 0x8032B6F4 (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(char*, EFile*, int);
};
class ParticleManager : public EResourceManager {
public:
    void AddRef(char* name, EFile* file, int flag);
};
void ParticleManager::AddRef(char* name, EFile* file, int flag) {
    EResourceManager::AddRef(name, file, flag);
}
