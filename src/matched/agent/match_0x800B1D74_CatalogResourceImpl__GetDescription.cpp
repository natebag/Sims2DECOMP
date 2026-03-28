/* CatalogResourceImpl::GetDescription(void) at 0x800B1D74 (16B) */

struct StringBuffer {
    char* m_buffer;
};

struct CatalogResourceImpl {
    char pad[0x08];
    void* m_description;

    StringBuffer GetDescription(void);
};

StringBuffer CatalogResourceImpl::GetDescription(void) {
    StringBuffer result;
    result.m_buffer = (char*)m_description;
    return result;
}
