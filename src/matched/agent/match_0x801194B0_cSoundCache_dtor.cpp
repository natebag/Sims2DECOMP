// FLAGS: -msdata=eabi -G 8
// 0x801194B0 cSoundCache::~cSoundCache (64b)
extern void cSoundCache_Shutdown(void*);
extern void __builtin_delete(void*);

void cSoundCache_dtor(void* self, int flags) {
    cSoundCache_Shutdown(self);
    if (flags & 1) {
        __builtin_delete(self);
    }
}
