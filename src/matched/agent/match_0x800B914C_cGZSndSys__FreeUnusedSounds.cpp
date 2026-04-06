extern void* gSndSys;
extern "C" void purgeCache(void*);
extern "C" void updateSounds(void*, int);
void cGZSndSys_FreeUnusedSounds() {
    if (gSndSys) {
        purgeCache(gSndSys);
        updateSounds(gSndSys, 0);
    }
}
