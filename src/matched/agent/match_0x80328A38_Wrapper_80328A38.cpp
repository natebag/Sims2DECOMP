/* EffectsEmitterManager::AddRef(char*, EFile*, int) at 0x80328A38 (32B) */
// 0x80328A38 (32 bytes)

class EFile;
class EResourceManager {
public:
    void AddRef(char*, EFile*, int);
};
class EffectsEmitterManager : public EResourceManager {
public:
    void AddRef(char* name, EFile* file, int flag);
};

void EffectsEmitterManager::AddRef(char* name, EFile* file, int flag) {
    EResourceManager::AddRef(name, file, flag);
}
