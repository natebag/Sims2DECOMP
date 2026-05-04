// ASMPROC_swap_adj: a=la b=mr
// ASMPROC_swap_adj: a=addi b=mr
// ASMPROC_swap_adj: a=addi b=la

extern char AptValueWithHash_vtable[];
extern void AptValue_ctor(void *, int);
extern void AptNativeHash_ctor(void *, int);

struct AptValueWithHash {
    char pad[32];
    AptValueWithHash(int, int);
};

AptValueWithHash::AptValueWithHash(int type, int hashSize) {
    AptValue_ctor(this, type);
    *(char **)((char *)this + 8) = AptValueWithHash_vtable;
    AptNativeHash_ctor((char *)this + 12, hashSize);
}
