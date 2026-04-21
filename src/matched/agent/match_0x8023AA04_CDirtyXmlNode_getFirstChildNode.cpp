// 0x8023AA04 (60B) CDirtyXmlNode::getFirstChildNode(void)

struct XmlVisitor_Base {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void* GetChild() = 0;
};

struct CDirtyXmlNode : public XmlVisitor_Base {
    char pad[16];
    int m_childIndex;
    void* getFirstChildNode();
};

void* CDirtyXmlNode::getFirstChildNode() {
    m_childIndex = 0;
    return GetChild();
}
