extern int vtbl_802A6DB8[];
extern void NH_Destroy_802A6DB8(void *, int);
extern void Val_PD_802A6DB8(void *, int);
extern void *gPool_802A6DB8;
extern void Pool_Dealloc_802A6DB8(void *, void *, unsigned int);

struct Obj_802A6DB8 {
    char pad[0x28];
    void operator delete(void *p) { Pool_Dealloc_802A6DB8(gPool_802A6DB8, p, 0x28); }
    ~Obj_802A6DB8();
};

Obj_802A6DB8::~Obj_802A6DB8()
{
    *(int*)((char*)this + 8) = (int)vtbl_802A6DB8;
    NH_Destroy_802A6DB8((char*)this + 0x0C, 2);
    Val_PD_802A6DB8(this, 0);
}
