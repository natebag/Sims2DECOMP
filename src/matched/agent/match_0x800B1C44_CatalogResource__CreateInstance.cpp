// CatalogResource::CreateInstance - allocates and initializes CatalogResource

extern int CatalogResource_vtable[];
extern void *__builtin_new(unsigned int size);

struct CatalogResource {
    int *m_vtable;   // 0x00
    int m_field4;    // 0x04
    int m_field8;    // 0x08
    int m_fieldC;    // 0x0C
};

CatalogResource *CatalogResource_CreateInstance() {
    CatalogResource *obj = (CatalogResource *)__builtin_new(16);
    register char *r13 asm("r13");
    int sda_val = (int)(r13 - 32080);
    obj->m_vtable = (int *)CatalogResource_vtable;
    obj->m_fieldC = sda_val;
    obj->m_field4 = sda_val;
    obj->m_field8 = sda_val;
    return obj;
}
