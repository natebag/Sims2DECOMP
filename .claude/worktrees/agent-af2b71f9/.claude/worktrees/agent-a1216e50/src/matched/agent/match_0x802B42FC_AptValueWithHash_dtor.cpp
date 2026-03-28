extern void AptNativeHash_Destroy(void *, int);
extern void AptValue_PreDestroy_vwh(void *, int);
extern void *gAptValGCPool_vwh;
extern void AptValGC_Dealloc_vwh(void *, void *, unsigned int);

struct AptValueWithHash_d {
    char pad[0x20];
    void operator delete(void *p) { AptValGC_Dealloc_vwh(gAptValGCPool_vwh, p, 0x20); }
    ~AptValueWithHash_d();
};

AptValueWithHash_d::~AptValueWithHash_d()
{
    AptNativeHash_Destroy((char*)this + 0x0C, 2);
    AptValue_PreDestroy_vwh(this, 0);
}
