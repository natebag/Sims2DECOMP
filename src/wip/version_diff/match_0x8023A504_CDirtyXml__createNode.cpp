extern int __vt_CDirtyXmlNode[];

void* operator_new(unsigned int);

struct CDirtyXmlNode {
    int* m_vtable;
    char* m_data;
    int m_nodeType;
};

CDirtyXmlNode* CDirtyXml_createNode(CDirtyXmlNode* parent, char* data) {
    int type = 3;
    if (*data == '<') {
        type = 1;
    }
    if (parent == 0) {
        parent = (CDirtyXmlNode*)operator_new(32);
        parent->m_vtable = __vt_CDirtyXmlNode;
    }
    parent->m_nodeType = type;
    parent->m_data = data;
    return parent;
}
