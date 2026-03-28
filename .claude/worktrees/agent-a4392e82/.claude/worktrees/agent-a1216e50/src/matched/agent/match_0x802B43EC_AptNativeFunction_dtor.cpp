extern int AptNativeFunc_vtbl[];
extern void AptNativeHash_Destroy_nf(void *, int);
extern void AptValue_PreDestroy_nf(void *, int);
extern void *gAptValGCPool_nf;
extern void AptValGC_Dealloc_nf(void *, void *, unsigned int);

struct AptNativeFunction_d {
    char pad[0x28];
    void operator delete(void *p) { AptValGC_Dealloc_nf(gAptValGCPool_nf, p, 0x28); }
    ~AptNativeFunction_d();
};

AptNativeFunction_d::~AptNativeFunction_d()
{
    *(int*)((char*)this + 8) = (int)AptNativeFunc_vtbl;
    AptNativeHash_Destroy_nf((char*)this + 0x0C, 2);
    AptValue_PreDestroy_nf(this, 0);
}
