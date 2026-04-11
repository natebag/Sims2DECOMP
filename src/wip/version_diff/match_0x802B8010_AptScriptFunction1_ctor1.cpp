struct AptScriptFunctionBase;
struct AptAction_DefineFunction;
struct AptCIH;

extern int AptScriptFunction1_vtable[];
extern void AptScriptFunctionBase_ctor_func(void *, int, AptScriptFunctionBase *, AptCIH *, int);

struct AptScriptFunction1 {
    char pad[0x38];
    AptScriptFunction1(AptScriptFunctionBase *base, AptAction_DefineFunction *def, AptCIH *cih);
};

AptScriptFunction1::AptScriptFunction1(AptScriptFunctionBase *base, AptAction_DefineFunction *def, AptCIH *cih)
{
    AptScriptFunctionBase_ctor_func(this, 0x2B, base, cih, 1);
    *(int*)((char*)this + 0x34) = (int)def;
    *(int*)((char*)this + 0x08) = (int)AptScriptFunction1_vtable;
}
