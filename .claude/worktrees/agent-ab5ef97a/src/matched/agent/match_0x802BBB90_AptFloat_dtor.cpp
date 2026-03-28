extern int AptFloat_vtbl[];
extern void AptValue_PreDestroy_f(void *, int);
extern void AptFloat_pool_dealloc(void *, int);

struct AptFloat_d {
    char pad[0x10];
    void operator delete(void *p) { AptFloat_pool_dealloc(p, 16); }
    ~AptFloat_d();
};

AptFloat_d::~AptFloat_d()
{
    *(int*)((char*)this + 8) = (int)AptFloat_vtbl;
    AptValue_PreDestroy_f(this, 0);
}
