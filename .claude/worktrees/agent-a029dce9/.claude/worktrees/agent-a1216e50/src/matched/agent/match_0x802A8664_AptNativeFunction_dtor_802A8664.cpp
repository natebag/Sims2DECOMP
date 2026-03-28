extern int AptNF_vtbl_802A8664[];
extern void AptNH_Destroy_802A8664(void *, int);
extern void AptVal_PD_802A8664(void *, int);
extern void *gPool_802A8664;
extern void Pool_Dealloc_802A8664(void *, void *, unsigned int);

struct AptNF_802A8664 {
    char pad[0x28];
    void operator delete(void *p) { Pool_Dealloc_802A8664(gPool_802A8664, p, 0x28); }
    ~AptNF_802A8664();
};

AptNF_802A8664::~AptNF_802A8664()
{
    *(int*)((char*)this + 8) = (int)AptNF_vtbl_802A8664;
    AptNH_Destroy_802A8664((char*)this + 0x0C, 2);
    AptVal_PD_802A8664(this, 0);
}
