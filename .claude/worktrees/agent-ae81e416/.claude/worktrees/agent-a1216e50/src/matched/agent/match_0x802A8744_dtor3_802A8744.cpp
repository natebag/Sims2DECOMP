extern int vt_802A8744[];
extern void nhd_802A8744(void *, int);
extern void vpd_802A8744(void *, int);
extern void *gp_802A8744;
extern void pd_802A8744(void *, void *, unsigned int);

struct D_802A8744 {
    char pad[0x24];
    void operator delete(void *p) { pd_802A8744(gp_802A8744, p, 0x24); }
    ~D_802A8744();
};

D_802A8744::~D_802A8744()
{
    *(int*)((char*)this + 8) = (int)vt_802A8744;
    nhd_802A8744((char*)this + 0x0C, 2);
    vpd_802A8744(this, 0);
}
