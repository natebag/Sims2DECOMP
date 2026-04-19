/* EffectsSequencerManager::AddRef(unsigned int, EFile*, int) at 0x80328B70 (32B) */
// 0x80328B70 (32 bytes)

class EFile;
class EResourceManager {
public:
    void AddRef(unsigned int, EFile*, int);
};
class EffectsSequencerManager : public EResourceManager {
public:
    void AddRef(unsigned int id, EFile* file, int flag);
};

void EffectsSequencerManager::AddRef(unsigned int id, EFile* file, int flag) {
    EResourceManager::AddRef(id, file, flag);
}
