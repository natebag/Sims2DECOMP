// 0x800A7C60 (68B) QuickStringSet::LoadFromDataID(ObjectDataID &)
// Technique: single `!r` produces subfic+adde (call returned 0 = success → 1)

class ObjectDataID;

class QuickStringSet {
public:
    int LoadFromDataID(ObjectDataID& id);
};

int QuickStringSet::LoadFromDataID(ObjectDataID& id) {
    char* vt = *(char**)this;
    short v2 = *(short*)((char*)&id + 4);
    short adj = *(short*)(vt + 232);
    void* fn = *(void**)(vt + 236);
    int v1 = *(int*)&id;
    int r = ((int (*)(void*, int, short))fn)((char*)this + adj, v1, v2);
    return !r;
}
