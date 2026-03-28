extern int AptNF_vtbl_802BA224[];
extern void AptNH_Destroy_802BA224(void *, int);
extern void AptVal_PD_802BA224(void *, int);
extern void *gPool_802BA224;
extern void Pool_Dealloc_802BA224(void *, void *, unsigned int);

struct AptNF_802BA224 {
    char pad[0x28];
    void operator delete(void *p) { Pool_Dealloc_802BA224(gPool_802BA224, p, 0x28); }
    ~AptNF_802BA224();
};

AptNF_802BA224::~AptNF_802BA224()
{
    *(int*)((char*)this + 8) = (int)AptNF_vtbl_802BA224;
    AptNH_Destroy_802BA224((char*)this + 0x0C, 2);
    AptVal_PD_802BA224(this, 0);
}
