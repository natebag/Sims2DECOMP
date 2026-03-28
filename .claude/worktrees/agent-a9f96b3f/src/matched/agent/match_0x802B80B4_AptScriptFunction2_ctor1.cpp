struct AptScriptFunctionBase;
struct AptAction_DefineFunction2;
struct AptCIH;

extern int AptScriptFunction2_vtable[];
extern void AptScriptFunctionBase_ctor_func2(void *, int, AptScriptFunctionBase *, AptCIH *, int);

struct AptScriptFunction2 {
    char pad[0x38];
    AptScriptFunction2(AptScriptFunctionBase *base, AptAction_DefineFunction2 *def, AptCIH *cih);
};

AptScriptFunction2::AptScriptFunction2(AptScriptFunctionBase *base, AptAction_DefineFunction2 *def, AptCIH *cih)
{
    AptScriptFunctionBase_ctor_func2(this, 0x2C, base, cih, 1);
    *(int*)((char*)this + 0x34) = (int)def;
    *(int*)((char*)this + 0x08) = (int)AptScriptFunction2_vtable;
}
