extern int vt_80281F54[];
extern void nhd_80281F54(void *, int);
extern void vpd_80281F54(void *, int);
extern void *gp_80281F54;
extern void pd_80281F54(void *, void *, unsigned int);

struct D_80281F54 {
    char pad[0x24];
    void operator delete(void *p) { pd_80281F54(gp_80281F54, p, 0x24); }
    ~D_80281F54();
};

D_80281F54::~D_80281F54()
{
    *(int*)((char*)this + 8) = (int)vt_80281F54;
    nhd_80281F54((char*)this + 0x0C, 2);
    vpd_80281F54(this, 0);
}
