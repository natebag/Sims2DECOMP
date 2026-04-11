extern int AptNF_vtbl_802BB6A0[];
extern void AptNH_Destroy_802BB6A0(void *, int);
extern void AptVal_PD_802BB6A0(void *, int);
extern void *gPool_802BB6A0;
extern void Pool_Dealloc_802BB6A0(void *, void *, unsigned int);

struct AptNF_802BB6A0 {
    char pad[0x28];
    void operator delete(void *p) { Pool_Dealloc_802BB6A0(gPool_802BB6A0, p, 0x28); }
    ~AptNF_802BB6A0();
};

AptNF_802BB6A0::~AptNF_802BB6A0()
{
    *(int*)((char*)this + 8) = (int)AptNF_vtbl_802BB6A0;
    AptNH_Destroy_802BB6A0((char*)this + 0x0C, 2);
    AptVal_PD_802BB6A0(this, 0);
}
