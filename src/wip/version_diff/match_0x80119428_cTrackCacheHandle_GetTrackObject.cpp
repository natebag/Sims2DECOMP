// FLAGS: -fno-elide-constructors
// 0x80119428 cTrackCacheHandle::GetTrackObject (64b)
void* track_lookup(void*, int, int);

void* GetTrackObject_test(char* self) {
    int id = *(int*)self;
    if (id == 0) return 0;
    void* mgr = *(void**)((char*)g_sda_trackmgr + 80);
    return track_lookup(mgr, id, 1);
}
