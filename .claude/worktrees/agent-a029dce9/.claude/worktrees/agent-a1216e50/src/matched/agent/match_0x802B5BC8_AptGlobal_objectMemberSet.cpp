struct AptValue;
struct EAStringC;

extern void *gGlobalPrototypeHash;
extern void *AptNativeHash_Lookup(void *, EAStringC *);
extern void AptNativeHash_Set(void *, EAStringC *, AptValue *);

struct AptGlobal {
    char pad[0x24];
    int objectMemberSet(AptValue *self, EAStringC *key, AptValue *value);
};

int AptGlobal::objectMemberSet(AptValue *self, EAStringC *key, AptValue *value)
{
    void *found = AptNativeHash_Lookup((char*)gGlobalPrototypeHash + 0x0C, key);
    if (found == 0) {
        AptNativeHash_Set((char*)this + 0x0C, key, value);
    }
    return 1;
}
