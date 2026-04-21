// 0x8023AC64 (52B) CDirtyXml::getFirstAttribute(void)
// Forward to CDirtyXmlNode::getFirstAttribute (varargs-signal), return this.

class CDirtyXmlNode {
public:
    void getFirstAttribute(...);
};

class CDirtyXml : public CDirtyXmlNode {
public:
    CDirtyXml* getFirstAttribute();
};

CDirtyXml* CDirtyXml::getFirstAttribute() {
    CDirtyXmlNode::getFirstAttribute();
    return this;
}
