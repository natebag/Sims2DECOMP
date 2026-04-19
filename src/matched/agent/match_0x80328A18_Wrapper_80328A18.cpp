/* EffectsEmitterManager::AddRef(unsigned int, EFile*, int) at 0x80328A18 (32B) */
// 0x80328A18 (32 bytes)

class EFile;
class EResourceManager {
public:
    void AddRef(unsigned int, EFile*, int);
};
class EffectsEmitterManager : public EResourceManager {
public:
    void AddRef(unsigned int id, EFile* file, int flag);
};

void EffectsEmitterManager::AddRef(unsigned int id, EFile* file, int flag) {
    EResourceManager::AddRef(id, file, flag);
}
