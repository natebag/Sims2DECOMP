struct StringBuffer {
    void *m_data;
};

class CatalogResourceImpl {
public:
    void *vtable;
    StringBuffer m_name;
    StringBuffer m_description;
    StringBuffer m_shortName;

    StringBuffer GetShortName(void);
};

StringBuffer CatalogResourceImpl::GetShortName(void) {
    return m_shortName;
}
