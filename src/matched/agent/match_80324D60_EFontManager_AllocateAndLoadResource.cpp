// 0x80324D60 (112 bytes)
typedef unsigned int uint;

struct EFile;
struct EStream;

struct EAHeap {
    void *MallocAligned(uint size, uint align, uint flags1, int flags2);
};
EAHeap *MainHeap(void);

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

struct ERFont : EResource {
    char _pad[108 - sizeof(void*)];
    ERFont(void);
    virtual void Load(EFile &file);
};

inline void *operator new(uint, void *p) { return p; }

struct EFontManager {
    ERFont *AllocateAndLoadResource(EFile *file, uint id1, uint id2);
};

ERFont *EFontManager::AllocateAndLoadResource(EFile *file, uint id1, uint id2)
{
    EAHeap *heap = MainHeap();
    void *mem = heap->MallocAligned(108, 16, 0, 0);
    ERFont *res = new(mem) ERFont;
    *(uint *)((char *)res + 8) = id2;
    res->Load(*file);
    return res;
}
