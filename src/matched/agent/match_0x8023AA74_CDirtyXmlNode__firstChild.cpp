// 0x8023AA74 (32B) CDirtyXmlNode::firstChild(void)
// If m_count > 0, return m_children[0]; else nullptr.

class CDirtyXmlNode {
public:
    char pad[16];
    int m_count;
    char pad2[8];
    CDirtyXmlNode** m_children;
    CDirtyXmlNode* firstChild();
};

CDirtyXmlNode* CDirtyXmlNode::firstChild() {
    CDirtyXmlNode* result = 0;
    if (m_count > 0) {
        result = m_children[0];
    }
    return result;
}
