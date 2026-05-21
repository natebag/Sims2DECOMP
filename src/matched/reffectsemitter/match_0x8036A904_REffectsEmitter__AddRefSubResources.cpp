// 0x8036A904 (96B) REffectsEmitter::AddRefSubResources(void)

extern "C" int helper_0x80326CF8(void* mgr, unsigned int id, void* file, int flag);  // EResourceManager::AddRef
extern char _textureman[];  // 0x804BE33C

class REffectsEmitter {
public:
    void AddRefSubResources();
};

void REffectsEmitter::AddRefSubResources() {
    void* p = *(void**)((char*)this + 20);
    *(int*)((char*)this + 28) = 0;
    if (p == 0) return;
    unsigned int id = *(unsigned int*)((char*)p + 192);
    if (id == 0) return;
    *(int*)((char*)this + 28) = helper_0x80326CF8(_textureman, id, 0, 0);
}
