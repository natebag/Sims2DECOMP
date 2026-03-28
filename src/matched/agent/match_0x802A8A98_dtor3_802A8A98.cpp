extern int vt_802A8A98[];
extern void nhd_802A8A98(void *, int);
extern void vpd_802A8A98(void *, int);
extern void *gp_802A8A98;
extern void pd_802A8A98(void *, void *, unsigned int);

struct D_802A8A98 {
    char pad[0x24];
    void operator delete(void *p) { pd_802A8A98(gp_802A8A98, p, 0x24); }
    ~D_802A8A98();
};

D_802A8A98::~D_802A8A98()
{
    *(int*)((char*)this + 8) = (int)vt_802A8A98;
    nhd_802A8A98((char*)this + 0x0C, 2);
    vpd_802A8A98(this, 0);
}
