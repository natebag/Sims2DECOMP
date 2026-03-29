/* ObjectDataID::SetNamespaceID(unsigned int) at 0x8015BBE8 (8B) */

struct ObjectDataID {
    unsigned int m_namespaceID;
    unsigned short m_resourceID;
    void SetNamespaceID(unsigned int id);
};

void ObjectDataID::SetNamespaceID(unsigned int id) {
    m_namespaceID = id;
}
