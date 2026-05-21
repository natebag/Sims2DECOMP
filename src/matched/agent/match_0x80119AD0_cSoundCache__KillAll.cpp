// 0x80119AD0 (72B) cSoundCache::KillAll(void)
// ASMPROC_replace_insn: match="lwz 0,0(31)" replacement="lwz 3,0(31)"
// ASMPROC_remove_mr: match="mr 3,0"
// ASMPROC_replace_insn: match="cmpwi 0,0,0" replacement="cmpwi 0,3,0"

void cTrack__Kill(void* self);

struct cSoundCache {
    void* arr[64];
    void KillAll();
};

void cSoundCache::KillAll() {
    void** it = arr;
    void** end = arr + 63;
    do {
        if (*it)
            cTrack__Kill(*it);
        it++;
    } while ((int)it <= (int)end);
}
