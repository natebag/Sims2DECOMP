// 0x8023AC98 (52B) CDirtyXml::getNextAttribute(void)
// Forward to CDirtyXmlNode::getNextAttribute (varargs signal), return this.

class CDirtyXmlNode {
public:
    void getNextAttribute(...);
};

class CDirtyXml : public CDirtyXmlNode {
public:
    CDirtyXml* getNextAttribute();
};

CDirtyXml* CDirtyXml::getNextAttribute() {
    CDirtyXmlNode::getNextAttribute();
    return this;
}
