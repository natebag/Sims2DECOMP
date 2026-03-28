extern int vt_802B655C[];
extern void nhd_802B655C(void *, int);
extern void vpd_802B655C(void *, int);
extern void *gp_802B655C;
extern void pd_802B655C(void *, void *, unsigned int);

struct D_802B655C {
    char pad[0x24];
    void operator delete(void *p) { pd_802B655C(gp_802B655C, p, 0x24); }
    ~D_802B655C();
};

D_802B655C::~D_802B655C()
{
    *(int*)((char*)this + 8) = (int)vt_802B655C;
    nhd_802B655C((char*)this + 0x0C, 2);
    vpd_802B655C(this, 0);
}
