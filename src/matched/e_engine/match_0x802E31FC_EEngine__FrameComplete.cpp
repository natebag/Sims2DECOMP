// 0x802E31FC EEngine::FrameComplete (60b)
// FLAGS: -fno-elide-constructors

struct EEvent {};

struct SchedVtbl {
    char pad[0x38];
    short adjust;
    short pad2;
    void (*fn)(void*, EEvent*);
};

struct EScheduler {
    char pad[0x338];
    SchedVtbl* vtbl;
};

extern EScheduler* _pSched;

struct EEngine {
    char pad[0x34];
    EEvent event;
};

void EEngine__FrameComplete(EEngine* self) {
    SchedVtbl* v = _pSched->vtbl;
    short a = v->adjust;
    void (*f)(void*, EEvent*) = v->fn;
    void* adjusted = (char*)_pSched + a;
    f(adjusted, &self->event);
}
