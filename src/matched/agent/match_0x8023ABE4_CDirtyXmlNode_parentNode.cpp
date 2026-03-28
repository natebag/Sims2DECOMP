struct CDirtyXmlNode {
    char _pad[0x0C];
    int m_parentNode;
    int parentNode();
};
int CDirtyXmlNode::parentNode() { return m_parentNode; }
