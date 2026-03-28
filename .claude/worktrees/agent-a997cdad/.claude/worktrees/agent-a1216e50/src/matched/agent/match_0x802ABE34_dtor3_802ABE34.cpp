extern int vt_802ABE34[];
extern void nhd_802ABE34(void *, int);
extern void vpd_802ABE34(void *, int);
extern void *gp_802ABE34;
extern void pd_802ABE34(void *, void *, unsigned int);

struct D_802ABE34 {
    char pad[0x30];
    void operator delete(void *p) { pd_802ABE34(gp_802ABE34, p, 0x30); }
    ~D_802ABE34();
};

D_802ABE34::~D_802ABE34()
{
    *(int*)((char*)this + 8) = (int)vt_802ABE34;
    nhd_802ABE34((char*)this + 0x0C, 2);
    vpd_802ABE34(this, 0);
}
