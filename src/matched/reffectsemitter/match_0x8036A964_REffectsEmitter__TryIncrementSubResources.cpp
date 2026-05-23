// 0x8036A964 REffectsEmitter::TryIncrementSubResources(void) (108B)

extern "C" int helper_0x80326A60(void* mgr, unsigned int id, void** outRes);
extern char _textureman[];

class REffectsEmitter {
public:
    int TryIncrementSubResources();
};

int REffectsEmitter::TryIncrementSubResources() {
    void* p = *(void**)((char*)this + 20);
    if (p == 0) return 1;
    unsigned int id = *(unsigned int*)((char*)p + 192);
    if (id != 0) {
        void* outRes;
        if (helper_0x80326A60(_textureman, id, &outRes) == 0) {
            return 0;
        }
        *(void**)((char*)this + 28) = outRes;
    }
    return 1;
}
