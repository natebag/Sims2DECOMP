// 0x8032B5D8 AllocateAndLoadResource (96b)
// FLAGS: -fno-schedule-insns
typedef unsigned int uint;
typedef unsigned long ulong;

struct EFile;
struct EResourceManager {
    char _pad[0xD20];
    void *Alloc(ulong size, uint group);
};
extern EResourceManager _particleman;

struct RParticle {
    char _pad[60];
    RParticle(void);
    void Load(EFile *file, uint flags);
};

inline void *operator new(uint, void *p) { return p; }

struct EParticleManager {
    RParticle *AllocateAndLoadResource(EFile *file, uint id1, uint id2);
};

RParticle *EParticleManager::AllocateAndLoadResource(EFile *file, uint id1, uint id2)
{
    void *ptr = _particleman.Alloc(60, 8);
    RParticle *res = new(ptr) RParticle;
    *(uint *)((char *)res + 8) = id2;
    res->Load(file, id1);
    return res;
}
