extern int vt_802B4594[];
extern void nhd_802B4594(void *, int);
extern void vpd_802B4594(void *, int);
extern void *gp_802B4594;
extern void pd_802B4594(void *, void *, unsigned int);

struct D_802B4594 {
    char pad[0x24];
    void operator delete(void *p) { pd_802B4594(gp_802B4594, p, 0x24); }
    ~D_802B4594();
};

D_802B4594::~D_802B4594()
{
    *(int*)((char*)this + 8) = (int)vt_802B4594;
    nhd_802B4594((char*)this + 0x0C, 2);
    vpd_802B4594(this, 0);
}
