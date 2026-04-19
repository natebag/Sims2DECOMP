/* EffectsAttachmentManager::AddRef(char*, EFile*, int) at 0x803288D8 (32B) */
// 0x803288D8 (32 bytes)

class EFile;
class EResourceManager {
public:
    void AddRef(char*, EFile*, int);
};
class EffectsAttachmentManager : public EResourceManager {
public:
    void AddRef(char* name, EFile* file, int flag);
};

void EffectsAttachmentManager::AddRef(char* name, EFile* file, int flag) {
    EResourceManager::AddRef(name, file, flag);
}
