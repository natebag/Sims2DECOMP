extern void *g_AptObjectConstructor;
extern int strcmp(const char *, const char *);

struct AptValue;
struct EAStringC {
    const char *text;
};

struct AptObject {
    AptValue *objectMemberLookup(AptValue *, EAStringC *) const;
};

AptValue *AptObject::objectMemberLookup(AptValue *, EAStringC *name) const {
    if (strcmp(name->text + 8, "constructor") != 0) {
        return 0;
    }
    return (AptValue *)g_AptObjectConstructor;
}
