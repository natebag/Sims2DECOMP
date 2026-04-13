// FLAGS: -fno-elide-constructors -msdata=eabi -G 8
// 0x80119428 cTrackCacheHandle::GetTrackObject (64b)
extern void* g_sda_trackmgr;
void* track_lookup(void*, int, int);

void* GetTrackObject_test(char* self) {
    int id = *(int*)self;
    if (id == 0) return 0;
    void* mgr = *(void**)((char*)g_sda_trackmgr + 0x50);
    return track_lookup(mgr, id, 1);
}
