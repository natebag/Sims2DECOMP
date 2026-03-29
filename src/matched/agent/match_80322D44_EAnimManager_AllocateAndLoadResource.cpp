// 0x80322D44 (88 bytes)
typedef unsigned int uint;
typedef unsigned long ulong;

struct EFile;
struct EResourceManager {
    void *Alloc(ulong size, uint group);
};
extern EResourceManager g_animResMgr;

struct ERAnim {
    void *m_vtable;
    uint m_field_004;
    uint m_field_008;
    ERAnim(void);
    void Load(EFile *file);
};

inline void *operator new(uint, void *p) { return p; }

struct EAnimManager {
    ERAnim *AllocateAndLoadResource(EFile *file, uint id1, uint id2);
};

ERAnim *EAnimManager::AllocateAndLoadResource(EFile *file, uint id1, uint id2)
{
    void *mem = g_animResMgr.Alloc(160, 8);
    ERAnim *res = new(mem) ERAnim;
    res->m_field_008 = id2;
    res->Load(file);
    return res;
}
