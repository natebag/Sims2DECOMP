// FLAGS: -msdata=eabi -G 8
// 0x800B1D74 CatalogResourceImpl::GetDescription (16b)
struct StringHandle {
    unsigned int m_handle;
};

class CatalogResourceImpl {
public:
    int vtable;
    unsigned int m_name;
    unsigned int m_description;
    unsigned int m_shortName;

    StringHandle GetDescription(void);
};

StringHandle CatalogResourceImpl::GetDescription(void) {
    StringHandle h;
    h.m_handle = m_description;
    return h;
}
