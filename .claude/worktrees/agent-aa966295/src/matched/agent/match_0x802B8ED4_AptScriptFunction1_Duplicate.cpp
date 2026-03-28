struct AptCIH;
struct AptScriptFunction1;
struct AptValueGC_PoolManager {
    char pad[4];
};

extern AptValueGC_PoolManager *gAptValuePool;
extern void *AptValueGC_AllocateAptValueGC(AptValueGC_PoolManager *, unsigned int);
extern void *AptScriptFunction1_copy_ctor(void *, AptScriptFunction1 *, AptCIH *);

struct AptScriptFunction1 {
    void *Duplicate(AptCIH *cih);
};

void *AptScriptFunction1::Duplicate(AptCIH *cih)
{
    void *mem = AptValueGC_AllocateAptValueGC(gAptValuePool, 0x38);
    return AptScriptFunction1_copy_ctor(mem, this, cih);
}
