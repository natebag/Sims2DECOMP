// FLAGS: -msdata=eabi -G 8
// 0x800B1D64 CatalogResourceImpl::GetName (16b)
struct StringHandle {
    unsigned int m_handle;
};

class CatalogResourceImpl {
public:
    int vtable;
    unsigned int m_name;
    unsigned int m_description;
    unsigned int m_shortName;

    StringHandle GetName(void);
};

StringHandle CatalogResourceImpl::GetName(void) {
    StringHandle h;
    h.m_handle = m_name;
    return h;
}
