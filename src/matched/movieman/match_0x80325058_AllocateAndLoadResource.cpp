// 0x80325058 AllocateAndLoadResource (188b)
// FLAGS: -fno-elide-constructors
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

struct EResourceManager {
    char _pad[0xD20];
};

struct ERMovie {
    ERMovie(EFile *file, uint a, uint b, uint c);
    virtual ~ERMovie(void);
};

inline void *operator new(uint, void *p) { return p; }

struct EMovieMan : EResourceManager {
    uint m_field_D20;
    ERMovie *AllocateAndLoadResource(EFile *file, uint id1, uint id2);
};

ERMovie *EMovieMan::AllocateAndLoadResource(EFile *file, uint id1, uint id2)
{
    uint saved_id2 = id2;
    uint saved_id1 = id1;
    int size1 = file->GetSize();
    void *mem = MainHeap()->Malloc(40, 0);
    ERMovie *res = new(mem) ERMovie(file, (uint)size1, saved_id1, this->m_field_D20);
    *(uint *)((char *)res + 8) = saved_id2;
    int size2 = file->GetSize();
    file->Seek(saved_id1 - ((uint)size2 - (uint)size1), 1);
    return res;
}
