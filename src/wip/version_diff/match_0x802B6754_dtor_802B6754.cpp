extern int vtbl_802B6754[];
extern void NH_Destroy_802B6754(void *, int);
extern void Val_PD_802B6754(void *, int);
extern void *gPool_802B6754;
extern void Pool_Dealloc_802B6754(void *, void *, unsigned int);

struct Obj_802B6754 {
    char pad[0x28];
    void operator delete(void *p) { Pool_Dealloc_802B6754(gPool_802B6754, p, 0x28); }
    ~Obj_802B6754();
};

Obj_802B6754::~Obj_802B6754()
{
    *(int*)((char*)this + 8) = (int)vtbl_802B6754;
    NH_Destroy_802B6754((char*)this + 0x0C, 2);
    Val_PD_802B6754(this, 0);
}
