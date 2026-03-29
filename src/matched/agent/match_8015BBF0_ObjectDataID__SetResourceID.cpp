/* ObjectDataID::SetResourceID(unsigned short) at 0x8015BBF0 (8B) */

struct ObjectDataID {
    unsigned int m_namespaceID;
    unsigned short m_resourceID;
    void SetResourceID(unsigned short id);
};

void ObjectDataID::SetResourceID(unsigned short id) {
    m_resourceID = id;
}
