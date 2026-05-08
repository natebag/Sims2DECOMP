/* ObjFnTableQuickData::LoadFromDataID(ObjectDataID &) - 0x801101F4 - 68 bytes */

struct ObjectDataID {
    unsigned int nsId;
    short resId;
};

struct ObjFnTableQuickData {
    int LoadFromDataID(ObjectDataID& dataID);
};

int ObjFnTableQuickData::LoadFromDataID(ObjectDataID& dataID) {
    int *vt = *(int **)this;
    short delta = *(short *)((char *)vt + 144);
    int (*func)(void*, unsigned int, short) = (int (*)(void*, unsigned int, short))*(void **)((char *)vt + 148);
    int result = func((char *)this + delta, dataID.nsId, dataID.resId);
    return !result;
}
