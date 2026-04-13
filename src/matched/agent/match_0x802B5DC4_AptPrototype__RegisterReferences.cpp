// 0x802B5DC4 AptPrototype::RegisterReferences (80b)
// FLAGS: -fno-schedule-insns

typedef void (*RegRefFn)(void *, int, void *);
void AptValueWithHash_RegisterReferences(void *self);
extern RegRefFn gAptRegRef;
extern char gAptProtoTypeInfo[12];

void AptPrototype_RegisterReferences(char *self)
{
    AptValueWithHash_RegisterReferences(self);
    int field20 = *(int *)(self + 0x20);
    if (field20 != 0) {
        gAptRegRef(self, field20, gAptProtoTypeInfo);
    }
}
