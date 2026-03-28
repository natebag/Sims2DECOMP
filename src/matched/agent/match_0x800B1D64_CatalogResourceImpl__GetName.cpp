/* CatalogResourceImpl::GetName(void) at 0x800B1D64 (16B) */

struct StringBuffer {
    char* m_buffer;
};

struct CatalogResourceImpl {
    char pad[0x04];
    void* m_name;

    StringBuffer GetName(void);
};

StringBuffer CatalogResourceImpl::GetName(void) {
    StringBuffer result;
    result.m_buffer = (char*)m_name;
    return result;
}
