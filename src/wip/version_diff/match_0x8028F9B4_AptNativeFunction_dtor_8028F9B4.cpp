extern int AptNF_vtbl_8028F9B4[];
extern void AptNH_Destroy_8028F9B4(void *, int);
extern void AptVal_PD_8028F9B4(void *, int);
extern void *gPool_8028F9B4;
extern void Pool_Dealloc_8028F9B4(void *, void *, unsigned int);

struct AptNF_8028F9B4 {
    char pad[0x28];
    void operator delete(void *p) { Pool_Dealloc_8028F9B4(gPool_8028F9B4, p, 0x28); }
    ~AptNF_8028F9B4();
};

AptNF_8028F9B4::~AptNF_8028F9B4()
{
    *(int*)((char*)this + 8) = (int)AptNF_vtbl_8028F9B4;
    AptNH_Destroy_8028F9B4((char*)this + 0x0C, 2);
    AptVal_PD_8028F9B4(this, 0);
}
