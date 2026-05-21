// 0x800BED18 (60B) IFFResFile2::GetByID(int, short, void (*)(void *, int))
// Direct port of ChainResFile::GetByID (identical bytes)

class IFFResFile2 {
public:
    void GetByID(int id, short version, void (*cb)(void*, int));
};

void IFFResFile2::GetByID(int id, short version, void (*cb)(void*, int)) {
    char* vt = *(char**)((char*)this + 12);
    short adj = *(short*)(vt + 152);
    void* fn = *(void**)(vt + 156);
    ((void (*)(void*, int, short, int, void (*)(void*, int)))fn)((char*)this + adj, id, version, 0, cb);
}
