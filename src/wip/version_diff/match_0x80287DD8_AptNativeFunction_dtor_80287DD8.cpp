extern int AptNF_vtbl_80287DD8[];
extern void AptNH_Destroy_80287DD8(void *, int);
extern void AptVal_PD_80287DD8(void *, int);
extern void *gPool_80287DD8;
extern void Pool_Dealloc_80287DD8(void *, void *, unsigned int);

struct AptNF_80287DD8 {
    char pad[0x28];
    void operator delete(void *p) { Pool_Dealloc_80287DD8(gPool_80287DD8, p, 0x28); }
    ~AptNF_80287DD8();
};

AptNF_80287DD8::~AptNF_80287DD8()
{
    *(int*)((char*)this + 8) = (int)AptNF_vtbl_80287DD8;
    AptNH_Destroy_80287DD8((char*)this + 0x0C, 2);
    AptVal_PD_80287DD8(this, 0);
}
