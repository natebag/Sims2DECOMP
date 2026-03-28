extern int AptXml_vtbl_d[];
extern void AptXmlNode_dtor(void *, int);
extern void *gAptValGCPool_b;
extern void AptValGC_Dealloc_b(void *, void *, unsigned int);

struct AptXml_d {
    char pad[0x2C];
    void operator delete(void *p) { AptValGC_Dealloc_b(gAptValGCPool_b, p, 0x2C); }
    ~AptXml_d();
};

AptXml_d::~AptXml_d()
{
    *(int*)((char*)this + 8) = (int)AptXml_vtbl_d;
    AptXmlNode_dtor(this, 0);
}
