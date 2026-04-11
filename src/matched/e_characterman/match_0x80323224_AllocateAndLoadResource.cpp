// 0x80323224 AllocateAndLoadResource (108b)
// FLAGS: -fno-schedule-insns
typedef unsigned int uint;
typedef unsigned long ulong;

struct EFile;
struct EStream;

struct EResourceManager {
    char _pad[0xD20];
    void *Alloc(ulong size, uint group);
};
extern EResourceManager _characterman;

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

struct ERCharacter : EResource {
    char _pad[52 - sizeof(void*)];
    ERCharacter(void);
    virtual void Load(EFile &file);
};

inline void *operator new(uint, void *p) { return p; }

struct ECharacterManager {
    ERCharacter *AllocateAndLoadResource(EFile *file, uint id1, uint id2);
};

ERCharacter *ECharacterManager::AllocateAndLoadResource(EFile *file, uint id1, uint id2)
{
    void *ptr = _characterman.Alloc(52, 8);
    ERCharacter *res = new(ptr) ERCharacter;
    *(uint *)((char *)res + 8) = id2;
    res->Load(*file);
    return res;
}
