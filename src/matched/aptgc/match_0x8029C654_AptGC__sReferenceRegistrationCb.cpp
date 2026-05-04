struct AptValueVTable {
    char pad[112];
    short registerReferencesThisOffset;
    short pad2;
    void (*registerReferences)(void *);
};

struct AptValue {
    unsigned int flags;
    char pad[4];
    AptValueVTable *vtable;
};

struct AptGC {
    static void sReferenceRegistrationCb(AptValue *, AptValue *, char *);
};

void AptGC::sReferenceRegistrationCb(AptValue *, AptValue *value, char *) {
    if ((value->flags & 0x40000000) == 0) {
        value->flags |= 0x40000000;
        AptValueVTable *vt = value->vtable;
        vt->registerReferences((char *)value + vt->registerReferencesThisOffset);
    }
}
