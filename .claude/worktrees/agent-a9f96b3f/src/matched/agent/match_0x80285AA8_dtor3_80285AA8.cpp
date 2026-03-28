extern int vt_80285AA8[];
extern void nhd_80285AA8(void *, int);
extern void vpd_80285AA8(void *, int);
extern void *gp_80285AA8;
extern void pd_80285AA8(void *, void *, unsigned int);

struct D_80285AA8 {
    char pad[0x30];
    void operator delete(void *p) { pd_80285AA8(gp_80285AA8, p, 0x30); }
    ~D_80285AA8();
};

D_80285AA8::~D_80285AA8()
{
    *(int*)((char*)this + 8) = (int)vt_80285AA8;
    nhd_80285AA8((char*)this + 0x0C, 2);
    vpd_80285AA8(this, 0);
}
