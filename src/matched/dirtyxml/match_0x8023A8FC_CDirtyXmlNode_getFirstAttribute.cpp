// CDirtyXmlNode::getFirstAttribute(void) at 0x8023A8FC (80B)
// PMF-via-vtable template with side-effect field zero (technique #36)

class CDirtyXmlNode;

struct XmlNodeVtable {
    char pad[0x20];
    short m_firstAttrOffset;                 // +0x20
    int (*m_firstAttrFn)(CDirtyXmlNode *, ...);  // +0x24
};

struct XmlNodeArg {
    XmlNodeVtable *m_vt;   // +0
    char pad[0x14];        // +4..+0x17
    int m_field18;         // +0x18 (zeroed by getFirstAttribute side effect)
};

class CDirtyXmlNode {
public:
    CDirtyXmlNode *getFirstAttribute(XmlNodeArg &node);
};

CDirtyXmlNode *CDirtyXmlNode::getFirstAttribute(XmlNodeArg &node) {
    XmlNodeVtable *vt = node.m_vt;
    node.m_field18 = 0;
    ((int (*)(CDirtyXmlNode *, ...))vt->m_firstAttrFn)(this, (char *)&node + vt->m_firstAttrOffset);
    return this;
}
