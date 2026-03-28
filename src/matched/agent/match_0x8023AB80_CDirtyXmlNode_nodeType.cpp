struct CDirtyXmlNode {
    char _pad[0x08];
    int m_nodeType;
    int nodeType();
};
int CDirtyXmlNode::nodeType() { return m_nodeType; }
