struct AptValue;
struct AptValueGC_PoolManager {
    char pad[4];
};

extern AptValueGC_PoolManager *gAptValuePool;
extern void *AptValueGC_AllocateAptValueGC(AptValueGC_PoolManager *, unsigned int);
extern void *AptArray_ctor(void *, int, AptValue **);

void *AptValueFactory_CreateArray(int count, AptValue **values)
{
    void *mem = AptValueGC_AllocateAptValueGC(gAptValuePool, 0x30);
    return AptArray_ctor(mem, count, values);
}
