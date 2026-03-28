extern int CDirtyXmlNode_nodeType(void *self);

struct CDirtyXmlImpl {
    int nodeType();
};

int CDirtyXmlImpl::nodeType() {
    return CDirtyXmlNode_nodeType(this);
}
