struct AptCIH;
struct AptScriptFunction2;
struct AptValueGC_PoolManager {
    char pad[4];
};

extern AptValueGC_PoolManager *gAptValuePool;
extern void *AptValueGC_AllocateAptValueGC(AptValueGC_PoolManager *, unsigned int);
extern void *AptScriptFunction2_copy_ctor(void *, AptScriptFunction2 *, AptCIH *);

struct AptScriptFunction2 {
    void *Duplicate(AptCIH *cih);
};

void *AptScriptFunction2::Duplicate(AptCIH *cih)
{
    void *mem = AptValueGC_AllocateAptValueGC(gAptValuePool, 0x38);
    return AptScriptFunction2_copy_ctor(mem, this, cih);
}
