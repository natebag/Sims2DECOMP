/* EffectsAttachmentManager::AddRef(unsigned int, EFile*, int) at 0x803288B8 (32B) */
// 0x803288B8 (32 bytes)

class EFile;
class EResourceManager {
public:
    void AddRef(unsigned int, EFile*, int);
};
class EffectsAttachmentManager : public EResourceManager {
public:
    void AddRef(unsigned int id, EFile* file, int flag);
};

void EffectsAttachmentManager::AddRef(unsigned int id, EFile* file, int flag) {
    EResourceManager::AddRef(id, file, flag);
}
