// FLAGS: -msdata=eabi -G 8
// 0x800B1C44 CatalogResource::CreateInstance (68b)
extern "C" void* __builtin_new(unsigned int);
extern int VTable[];
extern unsigned int ZERO_AD;

struct CatalogResourceImpl {
    int* vtable;
    unsigned int* m_name;
    unsigned int* m_description;
    unsigned int* m_shortName;
};

CatalogResourceImpl* CatalogResource_CreateInstance() {
    CatalogResourceImpl* p = (CatalogResourceImpl*)__builtin_new(16);
    p->vtable = VTable;
    p->m_name = &ZERO_AD;
    p->m_description = &ZERO_AD;
    p->m_shortName = &ZERO_AD;
    return p;
}
