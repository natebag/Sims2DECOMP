/* ObjectDataID::operator bool(void) const at 0x8015BBC0 (40B) */

struct ObjectDataID {
    unsigned int m_namespaceID;
    unsigned short m_resourceID;
    int IsValid() const;
};

int ObjectDataID::IsValid() const {
    int r = 0;
    if (m_namespaceID != 0) {
        if (m_resourceID != 0) {
            r = 1;
        }
    }
    return r;
}
