// 0x800B2A48 (60B) ChainResFile::GetByID(int, short, void (*)(void *, int))

class ChainResFile {
public:
    void GetByID(int id, short version, void (*cb)(void*, int));
};

void ChainResFile::GetByID(int id, short version, void (*cb)(void*, int)) {
    char* vt = *(char**)((char*)this + 12);
    short adj = *(short*)(vt + 152);
    void* fn = *(void**)(vt + 156);
    ((void (*)(void*, int, short, int, void (*)(void*, int)))fn)((char*)this + adj, id, version, 0, cb);
}
