struct StringBuffer {
    void *m_data;
};

class CatalogResourceImpl {
public:
    void *vtable;
    StringBuffer m_name;
    StringBuffer m_description;
    StringBuffer m_shortName;

    StringBuffer GetName(void);
};

StringBuffer CatalogResourceImpl::GetName(void) {
    return m_name;
}
