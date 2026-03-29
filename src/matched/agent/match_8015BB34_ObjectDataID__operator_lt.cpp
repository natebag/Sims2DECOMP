/* ObjectDataID::operator<(ObjectDataID &) const at 0x8015BB34 (56B) */

struct ObjectDataID {
    unsigned int m_namespaceID;
    unsigned short m_resourceID;
    int IsLessThan(ObjectDataID& other) const;
};

int ObjectDataID::IsLessThan(ObjectDataID& other) const {
    int r = 0;
    if (m_namespaceID < other.m_namespaceID ||
        (m_namespaceID == other.m_namespaceID && m_resourceID < other.m_resourceID)) {
        r = 1;
    }
    return r;
}
