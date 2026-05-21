// 0x800BED18 (60B) IFFResFile2::GetByID(int, short, void (*)(void*, int))

class IFFResFile2 {
public:
    void GetByID(int id, short sh, void (*cb)(void*, int));
};

void IFFResFile2::GetByID(int id, short sh, void (*cb)(void*, int)) {
    char* obj = (char*)this;
    char* vt = *(char**)(obj + 12);
    short adj = *(short*)(vt + 152);
    void* fn = *(void**)(vt + 156);
    typedef void (*Fn)(void*, int, short, int, void(*)(void*, int));
    ((Fn)fn)(obj + adj, id, sh, 0, cb);
}
