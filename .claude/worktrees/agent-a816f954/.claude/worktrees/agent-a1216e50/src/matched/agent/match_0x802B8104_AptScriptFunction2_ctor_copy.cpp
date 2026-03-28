struct AptScriptFunction2;
struct AptCIH;

extern int AptScriptFunction2_vtable[];
extern void AptScriptFunctionBase_ctor_copy2(void *, int, AptScriptFunction2 *, AptCIH *);

struct AptScriptFunction2 {
    char pad[0x38];
    AptScriptFunction2(AptScriptFunction2 *src, AptCIH *cih);
};

AptScriptFunction2::AptScriptFunction2(AptScriptFunction2 *src, AptCIH *cih)
{
    AptScriptFunctionBase_ctor_copy2(this, 0x2C, src, cih);
    *(int*)((char*)this + 0x08) = (int)AptScriptFunction2_vtable;
    *(int*)((char*)this + 0x34) = *(int*)((char*)src + 0x34);
}
