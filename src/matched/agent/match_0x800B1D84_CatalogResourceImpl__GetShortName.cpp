/* CatalogResourceImpl::GetShortName(void) at 0x800B1D84 (16B) */

struct StringBuffer {
    char* m_buffer;
};

struct CatalogResourceImpl {
    char pad[0x0C];
    void* m_shortName;

    StringBuffer GetShortName(void);
};

StringBuffer CatalogResourceImpl::GetShortName(void) {
    StringBuffer result;
    result.m_buffer = (char*)m_shortName;
    return result;
}
