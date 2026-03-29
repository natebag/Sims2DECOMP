// 0x80322D44 (88 bytes)
typedef unsigned int uint;
typedef unsigned long ulong;

struct EFile;
struct EResourceManager {
    char _pad[0xD20];
    void *Alloc(ulong size, uint group);
};
extern EResourceManager _animman;

struct ERAnim {
    char _pad[160];
    ERAnim(void);
    void Load(EFile *file);
};

inline void *operator new(uint, void *p) { return p; }

struct EAnimManager {
    ERAnim *AllocateAndLoadResource(EFile *file, uint id1, uint id2);
};

ERAnim *EAnimManager::AllocateAndLoadResource(EFile *file, uint id1, uint id2)
{
    void *ptr = _animman.Alloc(160, 8);
    ERAnim *res = new(ptr) ERAnim;
    *(uint *)((char *)res + 8) = id2;
    res->Load(file);
    return res;
}
