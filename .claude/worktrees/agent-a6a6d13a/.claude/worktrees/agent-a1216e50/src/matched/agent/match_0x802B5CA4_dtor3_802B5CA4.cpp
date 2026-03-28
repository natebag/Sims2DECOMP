extern int vt_802B5CA4[];
extern void nhd_802B5CA4(void *, int);
extern void vpd_802B5CA4(void *, int);
extern void *gp_802B5CA4;
extern void pd_802B5CA4(void *, void *, unsigned int);

struct D_802B5CA4 {
    char pad[0x24];
    void operator delete(void *p) { pd_802B5CA4(gp_802B5CA4, p, 0x24); }
    ~D_802B5CA4();
};

D_802B5CA4::~D_802B5CA4()
{
    *(int*)((char*)this + 8) = (int)vt_802B5CA4;
    nhd_802B5CA4((char*)this + 0x0C, 2);
    vpd_802B5CA4(this, 0);
}
