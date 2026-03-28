struct StringBuffer {
    void *m_data;
};

class CatalogResourceImpl {
public:
    void *vtable;
    StringBuffer m_name;
    StringBuffer m_description;
    StringBuffer m_shortName;

    StringBuffer GetDescription(void);
};

StringBuffer CatalogResourceImpl::GetDescription(void) {
    return m_description;
}
