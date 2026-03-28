extern int AptSFBCB_vtbl[];
extern void AptSFBase_dtor(void *, int);
extern void *gAptValGCPool_a;
extern void AptValGC_Dealloc_a(void *, void *, unsigned int);

struct AptSFBCB_d {
    char pad[0x48];
    void operator delete(void *p) { AptValGC_Dealloc_a(gAptValGCPool_a, p, 0x48); }
    ~AptSFBCB_d();
};

AptSFBCB_d::~AptSFBCB_d()
{
    *(int*)((char*)this + 8) = (int)AptSFBCB_vtbl;
    AptSFBase_dtor(this, 0);
}
