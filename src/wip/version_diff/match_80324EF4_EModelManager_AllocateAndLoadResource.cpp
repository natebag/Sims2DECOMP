// 0x80324EF4 (88 bytes)
typedef unsigned int uint;
typedef unsigned long ulong;

struct EFile;
struct EResourceManager {
    char _pad[0xD20];
    void *Alloc(ulong size, uint group);
};
extern EResourceManager _modelman;

struct ERModel {
    char _pad[384];
    ERModel(void);
    void LoadModel(EFile *file);
};

inline void *operator new(uint, void *p) { return p; }

struct EModelManager {
    ERModel *AllocateAndLoadResource(EFile *file, uint id1, uint id2);
};

ERModel *EModelManager::AllocateAndLoadResource(EFile *file, uint id1, uint id2)
{
    void *ptr = _modelman.Alloc(384, 8);
    ERModel *res = new(ptr) ERModel;
    *(uint *)((char *)res + 8) = id2;
    res->LoadModel(file);
    return res;
}
