// 0x8023AA94 CDirtyXmlNode::hasChildNodes (24B)
struct CDirtyXmlNode { char pad[0x10]; int m_firstChild; };
int CDirtyXmlNode_hasChildNodes(CDirtyXmlNode* self) {
    int r = 1;
    if (self->m_firstChild <= 0) r = 0;
    return r;
}
