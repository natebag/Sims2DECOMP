extern int AptExtern_vtbl[];
extern void AptValue_PreDestroy_e(void *, int);
extern void *gDogmaPool_e;
extern void DOGMA_Dealloc_e(void *, void *, unsigned int);

struct AptExtern_d {
    char pad[0x0C];
    void operator delete(void *p) { DOGMA_Dealloc_e(gDogmaPool_e, p, 0x0C); }
    ~AptExtern_d();
};

AptExtern_d::~AptExtern_d()
{
    *(int*)((char*)this + 8) = (int)AptExtern_vtbl;
    AptValue_PreDestroy_e(this, 0);
}
