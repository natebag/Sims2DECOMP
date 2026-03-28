extern int AptScriptFunction1_vtbl_d[];
extern void AptScriptFunctionBase_dtor(void *, int);

extern void *gAptValueGCPool;
extern void AptValueGC_Dealloc(void *, void *, unsigned int);

struct AptScriptFunction1_d {
    char pad[0x38];
    void operator delete(void *p) { AptValueGC_Dealloc(gAptValueGCPool, p, 0x38); }
    ~AptScriptFunction1_d();
};

AptScriptFunction1_d::~AptScriptFunction1_d()
{
    *(int*)((char*)this + 8) = (int)AptScriptFunction1_vtbl_d;
    AptScriptFunctionBase_dtor(this, 0);
}
