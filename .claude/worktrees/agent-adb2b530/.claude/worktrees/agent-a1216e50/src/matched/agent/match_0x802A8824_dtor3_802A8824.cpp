extern int vt_802A8824[];
extern void nhd_802A8824(void *, int);
extern void vpd_802A8824(void *, int);
extern void *gp_802A8824;
extern void pd_802A8824(void *, void *, unsigned int);

struct D_802A8824 {
    char pad[0x24];
    void operator delete(void *p) { pd_802A8824(gp_802A8824, p, 0x24); }
    ~D_802A8824();
};

D_802A8824::~D_802A8824()
{
    *(int*)((char*)this + 8) = (int)vt_802A8824;
    nhd_802A8824((char*)this + 0x0C, 2);
    vpd_802A8824(this, 0);
}
