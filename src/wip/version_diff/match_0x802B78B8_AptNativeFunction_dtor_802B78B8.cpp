extern int AptNF_vtbl_802B78B8[];
extern void AptNH_Destroy_802B78B8(void *, int);
extern void AptVal_PD_802B78B8(void *, int);
extern void *gPool_802B78B8;
extern void Pool_Dealloc_802B78B8(void *, void *, unsigned int);

struct AptNF_802B78B8 {
    char pad[0x28];
    void operator delete(void *p) { Pool_Dealloc_802B78B8(gPool_802B78B8, p, 0x28); }
    ~AptNF_802B78B8();
};

AptNF_802B78B8::~AptNF_802B78B8()
{
    *(int*)((char*)this + 8) = (int)AptNF_vtbl_802B78B8;
    AptNH_Destroy_802B78B8((char*)this + 0x0C, 2);
    AptVal_PD_802B78B8(this, 0);
}
