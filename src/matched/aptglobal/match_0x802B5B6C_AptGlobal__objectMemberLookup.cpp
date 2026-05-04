extern void *g_AptGlobalObject;
extern void *g_AptGlobalFallback;

struct EAStringC;
struct AptValue {
    unsigned int flags;
};

struct AptNativeHash {
    AptValue *Lookup(EAStringC *) const;
};

struct AptGlobal {
    AptValue *objectMemberLookup(AptValue *, EAStringC *) const;
};

AptValue *AptGlobal::objectMemberLookup(AptValue *, EAStringC *name) const {
    AptValue *value = ((AptNativeHash *)((char *)g_AptGlobalObject + 12))->Lookup(name);
    if (value != 0 && (value->flags & 0x08000000) != 0) {
        return value;
    }
    return ((AptNativeHash *)((char *)g_AptGlobalFallback + 12))->Lookup(name);
}
