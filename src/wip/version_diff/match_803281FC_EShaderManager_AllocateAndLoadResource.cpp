// 0x803281FC (108 bytes)
typedef unsigned int uint;
typedef unsigned long ulong;

struct EFile;
struct EStream;

struct EResourceManager {
    char _pad[0xD20];
    void *Alloc(ulong size, uint group);
};
extern EResourceManager _shaderman;

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

struct ERShader : EResource {
    char _pad[108 - sizeof(void*)];
    ERShader(void);
    virtual void Load(EFile &file);
};

inline void *operator new(uint, void *p) { return p; }

struct EShaderManager {
    ERShader *AllocateAndLoadResource(EFile *file, uint id1, uint id2);
};

ERShader *EShaderManager::AllocateAndLoadResource(EFile *file, uint id1, uint id2)
{
    void *ptr = _shaderman.Alloc(108, 8);
    ERShader *res = new(ptr) ERShader;
    *(uint *)((char *)res + 8) = id2;
    res->Load(*file);
    return res;
}
