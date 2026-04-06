// FLAGS: -msdata=eabi -G 8
// 0x800B1D40 CatalogResourceImpl::CatalogResourceImpl (36b)
extern int VTable[];
extern unsigned int ZERO_AD;

struct CatalogResourceImpl {
    int* vtable;
    unsigned int* m_name;
    unsigned int* m_description;
    unsigned int* m_shortName;

    CatalogResourceImpl();
};

CatalogResourceImpl::CatalogResourceImpl() {
    vtable = VTable;
    m_name = &ZERO_AD;
    m_description = &ZERO_AD;
    m_shortName = &ZERO_AD;
}
