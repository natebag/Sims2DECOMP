// 0x8036A964 REffectsEmitter::TryIncrementSubResources(void) (108B)
//
// Resolved by PURE source-only `negated-test-fallthrough` technique
// (S16-promoted #5). Inverted the `if (id == 0) return 1;` early-return
// into `if (id != 0) { main_path } return 1;` polarity flip. The less
// common case (the main bl path) becomes the inner branch, matching
// DOL's bne-skip-and-fallthrough structure.

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
