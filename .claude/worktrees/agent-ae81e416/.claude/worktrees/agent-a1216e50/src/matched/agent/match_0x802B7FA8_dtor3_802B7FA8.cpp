extern int vt_802B7FA8[];
extern void nhd_802B7FA8(void *, int);
extern void vpd_802B7FA8(void *, int);
extern void *gp_802B7FA8;
extern void pd_802B7FA8(void *, void *, unsigned int);

struct D_802B7FA8 {
    char pad[0x34];
    void operator delete(void *p) { pd_802B7FA8(gp_802B7FA8, p, 0x34); }
    ~D_802B7FA8();
};

D_802B7FA8::~D_802B7FA8()
{
    *(int*)((char*)this + 8) = (int)vt_802B7FA8;
    nhd_802B7FA8((char*)this + 0x0C, 2);
    vpd_802B7FA8(this, 0);
}
