// 0x80324BF4 (96 bytes)
typedef unsigned int uint;
typedef unsigned long ulong;

struct EFile;
struct EResourceManager {
    char _pad[0xD20];
    void *Alloc(ulong size, uint group);
};
extern EResourceManager _flashman;

struct ERFlash {
    char _pad[24];
    ERFlash(void);
    void Load(EFile *file, uint flags);
};

inline void *operator new(uint, void *p) { return p; }

struct EFlashManager {
    ERFlash *AllocateAndLoadResource(EFile *file, uint id1, uint id2);
};

ERFlash *EFlashManager::AllocateAndLoadResource(EFile *file, uint id1, uint id2)
{
    void *ptr = _flashman.Alloc(24, 8);
    ERFlash *res = new(ptr) ERFlash;
    *(uint *)((char *)res + 8) = id2;
    res->Load(file, id1);
    return res;
}
