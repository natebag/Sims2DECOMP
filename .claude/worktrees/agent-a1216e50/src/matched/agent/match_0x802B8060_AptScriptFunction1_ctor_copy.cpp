struct AptScriptFunction1;
struct AptCIH;

extern int AptScriptFunction1_vtable[];
extern void AptScriptFunctionBase_ctor_copy(void *, int, AptScriptFunction1 *, AptCIH *);

struct AptScriptFunction1 {
    char pad[0x38];
    AptScriptFunction1(AptScriptFunction1 *src, AptCIH *cih);
};

AptScriptFunction1::AptScriptFunction1(AptScriptFunction1 *src, AptCIH *cih)
{
    AptScriptFunctionBase_ctor_copy(this, 0x2B, src, cih);
    *(int*)((char*)this + 0x08) = (int)AptScriptFunction1_vtable;
    *(int*)((char*)this + 0x34) = *(int*)((char*)src + 0x34);
}
