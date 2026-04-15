// 0x8023AAB0 (40B) CDirtyXmlNode::lastChild(void)

struct Node;

struct CDirtyXmlNode {
    char pad[16];
    int m_count;
    char pad2[8];
    Node** m_children;
    Node* lastChild();
};

Node* CDirtyXmlNode::lastChild() {
    Node* r = 0;
    if (m_count > 0) {
        r = m_children[m_count - 1];
    }
    return r;
}
