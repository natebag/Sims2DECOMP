extern int AptNone_vtbl[];
extern void AptValue_PreDestroy_n(void *, int);
extern void *gDogmaPool_n;
extern void DOGMA_Dealloc_n(void *, void *, unsigned int);

struct AptNone_d {
    char pad[0x0C];
    void operator delete(void *p) { DOGMA_Dealloc_n(gDogmaPool_n, p, 0x0C); }
    ~AptNone_d();
};

AptNone_d::~AptNone_d()
{
    *(int*)((char*)this + 8) = (int)AptNone_vtbl;
    AptValue_PreDestroy_n(this, 0);
}
