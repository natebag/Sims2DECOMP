extern int AptScriptFunction2_vtbl_d[];
extern void AptScriptFunctionBase_dtor2(void *, int);

extern void *gAptValueGCPool2;
extern void AptValueGC_Dealloc2(void *, void *, unsigned int);

struct AptScriptFunction2_d {
    char pad[0x38];
    void operator delete(void *p) { AptValueGC_Dealloc2(gAptValueGCPool2, p, 0x38); }
    ~AptScriptFunction2_d();
};

AptScriptFunction2_d::~AptScriptFunction2_d()
{
    *(int*)((char*)this + 8) = (int)AptScriptFunction2_vtbl_d;
    AptScriptFunctionBase_dtor2(this, 0);
}
