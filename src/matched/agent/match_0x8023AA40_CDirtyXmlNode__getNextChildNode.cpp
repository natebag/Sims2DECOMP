/* CDirtyXmlNode::getNextChildNode(void) at 0x8023AA40 (48B) */

struct CDirtyXmlNode_GNCN {
    char _pad0[16];
    int m_count;       // 0x10
    int m_index;       // 0x14
    char _pad1[4];
    void** m_children; // 0x1c

    void* getNextChildNode();
};

void* CDirtyXmlNode_GNCN::getNextChildNode() {
    void* result = 0;
    int idx = m_index;
    if (idx < m_count) {
        result = m_children[idx];
        m_index = idx + 1;
    }
    return result;
}
