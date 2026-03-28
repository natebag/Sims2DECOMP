struct EAStringC;
struct AptValue;

extern void *AptNativeHash_Lookup(void *, EAStringC *);
extern void AptNativeHash_Set(void *, EAStringC *, AptValue *);

struct AptNativeHash {
    char pad[0x14];
    void SetIfNotExists(EAStringC *key, AptValue *value);
};

void AptNativeHash::SetIfNotExists(EAStringC *key, AptValue *value)
{
    void *found = AptNativeHash_Lookup(this, key);
    if (found == 0) {
        AptNativeHash_Set(this, key, value);
    }
}
