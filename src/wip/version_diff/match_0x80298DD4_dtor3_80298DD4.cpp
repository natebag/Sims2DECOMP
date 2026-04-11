extern int vt_80298DD4[];
extern void nhd_80298DD4(void *, int);
extern void vpd_80298DD4(void *, int);
extern void *gp_80298DD4;
extern void pd_80298DD4(void *, void *, unsigned int);

struct D_80298DD4 {
    char pad[0x68];
    void operator delete(void *p) { pd_80298DD4(gp_80298DD4, p, 0x68); }
    ~D_80298DD4();
};

D_80298DD4::~D_80298DD4()
{
    *(int*)((char*)this + 8) = (int)vt_80298DD4;
    nhd_80298DD4((char*)this + 0x0C, 2);
    vpd_80298DD4(this, 0);
}
