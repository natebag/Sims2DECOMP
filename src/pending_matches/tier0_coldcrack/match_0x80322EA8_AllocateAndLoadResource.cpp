// 0x80322EA8 AllocateAndLoadResource (172b)
// FLAGS: -fno-elide-constructors -fno-schedule-insns -fno-schedule-insns2
typedef unsigned int uint;

struct EAHeap {
    void *Malloc(uint size, int flags);
};
EAHeap *MainHeap(void);

struct EFileHead {
    char _pad[40];
};

struct EFile : EFileHead {
    virtual ~EFile(void);
    virtual void _m2(void);
    virtual void _m3(void);
    virtual void _m4(void);
    virtual void Seek(uint pos, uint mode);
    virtual int GetSize(void);
};

struct EResource {
    EResource(void);
    virtual ~EResource(void);
};

struct ERAudioStream : EResource {
    char _pad[32 - sizeof(EResource)];
    inline ERAudioStream(void) : EResource() {}
    virtual ~ERAudioStream(void);
};

inline void *operator new(uint, void *p) { return p; }

struct EAudioStreamMan {
    ERAudioStream *AllocateAndLoadResource(EFile *file, uint id1, uint id2);
};

ERAudioStream *EAudioStreamMan::AllocateAndLoadResource(EFile *file, uint id1, uint id2)
{
    int first = file->GetSize();
    void *mem = MainHeap()->Malloc(32, 0);
    ERAudioStream *res = new(mem) ERAudioStream;
    *(uint *)((char *)res + 24) = (uint)first;
    *(uint *)((char *)res + 28) = (uint)first + id1 - 1;
    *(uint *)((char *)res + 8) = id2;
    *(EFile **)((char *)res + 20) = file;
    file->Seek(id1, 1);
    return res;
}
