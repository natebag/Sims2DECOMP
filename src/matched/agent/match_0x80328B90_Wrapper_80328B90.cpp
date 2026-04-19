/* EffectsSequencerManager::AddRef(char*, EFile*, int) at 0x80328B90 (32B) */
// 0x80328B90 (32 bytes)

class EFile;
class EResourceManager {
public:
    void AddRef(char*, EFile*, int);
};
class EffectsSequencerManager : public EResourceManager {
public:
    void AddRef(char* name, EFile* file, int flag);
};

void EffectsSequencerManager::AddRef(char* name, EFile* file, int flag) {
    EResourceManager::AddRef(name, file, flag);
}
