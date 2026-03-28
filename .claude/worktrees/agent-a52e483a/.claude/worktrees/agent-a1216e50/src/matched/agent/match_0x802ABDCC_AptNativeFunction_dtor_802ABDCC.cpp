extern int AptNF_vtbl_802ABDCC[];
extern void AptNH_Destroy_802ABDCC(void *, int);
extern void AptVal_PD_802ABDCC(void *, int);
extern void *gPool_802ABDCC;
extern void Pool_Dealloc_802ABDCC(void *, void *, unsigned int);

struct AptNF_802ABDCC {
    char pad[0x28];
    void operator delete(void *p) { Pool_Dealloc_802ABDCC(gPool_802ABDCC, p, 0x28); }
    ~AptNF_802ABDCC();
};

AptNF_802ABDCC::~AptNF_802ABDCC()
{
    *(int*)((char*)this + 8) = (int)AptNF_vtbl_802ABDCC;
    AptNH_Destroy_802ABDCC((char*)this + 0x0C, 2);
    AptVal_PD_802ABDCC(this, 0);
}
