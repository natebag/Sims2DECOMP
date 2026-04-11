// 0x80328678 AllocateAndLoadResource (108b)
// FLAGS: -fno-schedule-insns
typedef unsigned int uint;
typedef unsigned long ulong;

struct EFile;
struct EStream;

struct EResourceManager {
    char _pad[0xD20];
    void *Alloc(ulong size, uint group);
};
extern EResourceManager _textureman;

struct EResource {
    virtual ~EResource(void);
    virtual void DelRef(void);
    virtual void AddRef(void);
    virtual void Refresh(void);
    virtual void SafeDelete(void);
    virtual void Write(EStream &s);
    virtual void Read(EStream &s);
    virtual bool IsSafeToDelete(void);
    virtual void Load(EFile &file);
    virtual void Refresh(EFile *file);
    virtual void Init(void);
    virtual void DelRefSubResources(void);
};

struct ERTexture : EResource {
    char _pad[24 - sizeof(void*)];
    ERTexture(void);
    virtual void Load(EFile &file);
};

inline void *operator new(uint, void *p) { return p; }

struct ETextureManager {
    ERTexture *AllocateAndLoadResource(EFile *file, uint id1, uint id2);
};

ERTexture *ETextureManager::AllocateAndLoadResource(EFile *file, uint id1, uint id2)
{
    void *ptr = _textureman.Alloc(24, 8);
    ERTexture *res = new(ptr) ERTexture;
    *(uint *)((char *)res + 8) = id2;
    res->Load(*file);
    return res;
}
