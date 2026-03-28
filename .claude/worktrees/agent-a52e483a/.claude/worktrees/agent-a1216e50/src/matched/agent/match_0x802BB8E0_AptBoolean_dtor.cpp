extern int AptBoolean_vtbl[];
extern void AptValue_PreDestroy_v(void *, int);
extern void AptBoolean_pool_dealloc(void *, int);

struct AptBoolean_d {
    char pad[0x10];
    void operator delete(void *p) { AptBoolean_pool_dealloc(p, 16); }
    ~AptBoolean_d();
};

AptBoolean_d::~AptBoolean_d()
{
    *(int*)((char*)this + 8) = (int)AptBoolean_vtbl;
    AptValue_PreDestroy_v(this, 0);
}
