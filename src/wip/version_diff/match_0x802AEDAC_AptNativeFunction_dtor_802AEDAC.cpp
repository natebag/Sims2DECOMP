extern int AptNF_vtbl_802AEDAC[];
extern void AptNH_Destroy_802AEDAC(void *, int);
extern void AptVal_PD_802AEDAC(void *, int);
extern void *gPool_802AEDAC;
extern void Pool_Dealloc_802AEDAC(void *, void *, unsigned int);

struct AptNF_802AEDAC {
    char pad[0x28];
    void operator delete(void *p) { Pool_Dealloc_802AEDAC(gPool_802AEDAC, p, 0x28); }
    ~AptNF_802AEDAC();
};

AptNF_802AEDAC::~AptNF_802AEDAC()
{
    *(int*)((char*)this + 8) = (int)AptNF_vtbl_802AEDAC;
    AptNH_Destroy_802AEDAC((char*)this + 0x0C, 2);
    AptVal_PD_802AEDAC(this, 0);
}
