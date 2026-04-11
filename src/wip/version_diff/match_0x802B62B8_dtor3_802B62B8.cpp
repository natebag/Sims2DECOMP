extern int vt_802B62B8[];
extern void nhd_802B62B8(void *, int);
extern void vpd_802B62B8(void *, int);
extern void *gp_802B62B8;
extern void pd_802B62B8(void *, void *, unsigned int);

struct D_802B62B8 {
    char pad[0x24];
    void operator delete(void *p) { pd_802B62B8(gp_802B62B8, p, 0x24); }
    ~D_802B62B8();
};

D_802B62B8::~D_802B62B8()
{
    *(int*)((char*)this + 8) = (int)vt_802B62B8;
    nhd_802B62B8((char*)this + 0x0C, 2);
    vpd_802B62B8(this, 0);
}
