extern int AptInteger_vtbl[];
extern void AptValue_PreDestroy_i(void *, int);
extern void AptInteger_pool_dealloc(void *, int);

struct AptInteger_d {
    char pad[0x10];
    void operator delete(void *p) { AptInteger_pool_dealloc(p, 16); }
    ~AptInteger_d();
};

AptInteger_d::~AptInteger_d()
{
    *(int*)((char*)this + 8) = (int)AptInteger_vtbl;
    AptValue_PreDestroy_i(this, 0);
}
