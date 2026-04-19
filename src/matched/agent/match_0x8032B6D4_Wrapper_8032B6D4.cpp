/* ParticleManager::AddRef(unsigned int, EFile*, int) at 0x8032B6D4 (32B) */
// 0x8032B6D4 (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(unsigned int, EFile*, int);
};
class ParticleManager : public EResourceManager {
public:
    void AddRef(unsigned int id, EFile* file, int flag);
};
void ParticleManager::AddRef(unsigned int id, EFile* file, int flag) {
    EResourceManager::AddRef(id, file, flag);
}
