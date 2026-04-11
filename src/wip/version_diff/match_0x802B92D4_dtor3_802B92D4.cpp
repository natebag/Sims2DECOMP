extern int vt_802B92D4[];
extern void nhd_802B92D4(void *, int);
extern void vpd_802B92D4(void *, int);
extern void *gp_802B92D4;
extern void pd_802B92D4(void *, void *, unsigned int);

struct D_802B92D4 {
    char pad[0x24];
    void operator delete(void *p) { pd_802B92D4(gp_802B92D4, p, 0x24); }
    ~D_802B92D4();
};

D_802B92D4::~D_802B92D4()
{
    *(int*)((char*)this + 8) = (int)vt_802B92D4;
    nhd_802B92D4((char*)this + 0x0C, 2);
    vpd_802B92D4(this, 0);
}
